#include "d03.h"

#include <exception>
#include <iostream>
#include <limits>
#include <numeric>

#include <util/string_parser.h>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

template<typename T>
Point2<T>::Point2()
		:x(0), y(0){
}

Answer D03::part_1(std::istream& in){
	parse_input(in);

	auto distance = [](const Point& point){
		return std::abs(point.x) + std::abs(point.y);
	};

	int min_dist = std::numeric_limits<int>::max();
	auto points = find_intersections();

	for (const Point& point: points){
		int dist = distance(point);
		//also checks that the minimum distance doesn't include the origin
		if (dist < min_dist && dist){
			min_dist = dist;
		}
	}

	return Answer(min_dist);
}

Answer D03::part_2(std::istream& in){
	parse_input(in);

	auto get_line_len = [this](const Line& line){
		return line_horizontal(line) ? line.p2.x - line.p1.x : line.p2.y - line.p1.y;
	};

	auto get_path_lengths = [this, &get_line_len](const std::vector<Point>& path){
		std::vector<int> ret(path.size() - 1);
		for (std::size_t i = 0; i < path.size() - 1; ++i){
			ret[i] = get_line_len(get_line(path[i], path[i + 1]));
		}
		return ret;
	};

	//one line from path1 and one line from path2
	//the ints are the indices of the first (w.r.t. each path) point of each line
	typedef std::pair<int, int> Lines;

	std::vector<Lines> potential_lines;
	//lower and upper bound on the minimum distance
	int min_dist_lower = std::numeric_limits<int>::max();
	int min_dist_upper = min_dist_lower;

	auto lengths1 = get_path_lengths(path1);
	auto lengths2 = get_path_lengths(path2);

	//used as lvalue for call to get_close_intersect(...)
	Point dummy;
	int dist1 = 0;

	for (std::size_t i = 0; i < lengths1.size() && dist1 <= min_dist_upper; ++i){
		int dist2 = 0;

		for (std::size_t j = 0; j < lengths2.size() && (dist1 + dist2) <= min_dist_upper; ++j){
			//if the two lines intersect
			if (get_close_intersect(
					get_line(path1[i], path1[i + 1]),
					get_line(path2[j], path2[j + 1]),
					dummy)){
				//ignore first lines of both paths
				if (!i && !j){
					continue;
				}

				int curr_lower = dist1 + dist2;
				int curr_upper = curr_lower + lengths1[i] + lengths2[j];

				min_dist_upper = std::min(curr_upper, min_dist_upper);
				//previously added lines cannot be minima because the upper bound breaks the previous lower bound
				if (min_dist_upper < min_dist_lower){
					potential_lines.clear();
					min_dist_lower = min_dist_upper;
				}
				min_dist_lower = std::min(curr_lower, min_dist_lower);

				potential_lines.push_back(Lines{i, j});
			}

			dist2 += lengths2[j];
		}

		dist1 += lengths1[i];
	}

	auto get_point_dist = [](const Point& p1, const Point& p2){
		return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
	};

	//hacky fix, min_dist upper bound doesn't work
	int min_dist = std::numeric_limits<int>::max();
	for (const auto& lines: potential_lines){
		//sums distances on [0, line_num)
		int dist = std::accumulate(lengths1.begin(), lengths1.begin() + lines.first, 0);
		dist += std::accumulate(lengths2.begin(), lengths2.begin() + lines.second, 0);
		//adds the last stretch
		dist += get_point_dist(path1[lines.first], path2[lines.second]);

		min_dist = std::min(dist, min_dist);
	}

	return Answer(min_dist);
}

void D03::parse_input(std::istream& in){
	auto get_path = [](const std::string& line){
		Point curr;
		std::vector<Point> ret{curr};

		auto parts = util::str_split(line, ",");
		for (const auto& part: parts){
			int distance = std::stoi(part.substr(1));

			switch (part[0]){
			case 'U':
				curr.y += distance;
				break;
			case 'D':
				curr.y -= distance;
				break;
			case 'L':
				curr.x -= distance;
				break;
			case 'R':
				curr.x += distance;
				break;
			}

			ret.push_back(curr);
		}

		return ret;
	};

	std::string line;
	std::getline(in, line);
	path1 = get_path(line);
	std::getline(in, line);
	path2 = get_path(line);
}

bool D03::line_horizontal(const Line& line) const{
	if (line.p1.y == line.p2.y){
		return true;
	}
	else if (line.p1.x == line.p2.x){
		return false;
	}
	else{
		throw std::exception();
	}
}

D03::Line D03::get_line(const Point& p1, const Point& p2) const{
	Line ret{p1, p2};

	//order the points on the line's defining axis
	if (line_horizontal(ret)){
		if (p1.x > p2.x){
			std::swap(ret.p1, ret.p2);
		}
	}
	else{
		if (p1.y > p2.y){
			std::swap(ret.p1, ret.p2);
		}
	}

	return ret;
}

bool D03::get_close_intersect(const Line& l1, const Line& l2, Point& ret) const{
	bool l1_horizontal = line_horizontal(l1);
	bool l2_horizontal = line_horizontal(l2);

	auto in_bounds = [](int x, int a, int b){
		return a <= x && x <= b;
	};

	auto set = [](Point& point, int x, int y){
		point.x = x;
		point.y = y;
	};

	//1 stands for line 1 and 2 stands for line 2. a and b defines the interval
	auto abs_closest = [&in_bounds](int a1, int b1, int a2, int b2){
		//[a, b] is the overlap
		int a = std::max(a1, a2);
		int b = std::min(b1, b2);

		if (in_bounds(0, a, b)){
			return 0;
		}
		return std::abs(a) < std::abs(b) ? a : b;
	};

	//one is vertical and one is horizontal
	if (l1_horizontal ^ l2_horizontal){
		if (l1_horizontal && in_bounds(l2.p1.x, l1.p1.x, l1.p2.x) && in_bounds(l1.p1.y, l2.p1.y, l2.p2.y)){
			set(ret, l2.p1.x, l1.p1.y);
		}
		else if (l2_horizontal && in_bounds(l1.p1.x, l2.p1.x, l2.p2.x) && in_bounds(l2.p1.y, l1.p1.y, l1.p2.y)){
			set(ret, l1.p1.x, l2.p1.y);
		}
		else{
			return false;
		}
	}
	//both are vertical or horizontal
	else{
		//horizontal with matching y
		if (l1_horizontal && l1.p1.y == l2.p1.y){
			//disjoint lines
			if (l1.p2.x < l2.p1.x || l2.p2.x < l1.p1.x){
				return false;
			}
			set(ret, abs_closest(l1.p1.x, l1.p2.x, l2.p1.x, l2.p2.x), l1.p1.y);
		}
		//vertical with matching x
		else if (!l1_horizontal && l1.p1.x == l2.p1.x){
			//disjoint lines
			if (l1.p2.y < l2.p1.y || l2.p2.y < l1.p1.y){
				return false;
			}
			set(ret, l1.p1.x, abs_closest(l1.p1.y, l1.p2.y, l2.p1.y, l2.p2.y));
		}
		else{
			return false;
		}
	}

	return true;
}

std::vector<D03::Point> D03::find_intersections() const{
	std::vector<Point> ret;
	Point intersect;

	for (std::size_t i = 0; i < path1.size() - 1; ++i){
		for (std::size_t j = 0; j < path2.size() - 1; ++j){
			if (get_close_intersect(
					get_line(path1[i], path1[i + 1]),
					get_line(path2[j], path2[j + 1]),
					intersect)){
				ret.push_back(intersect);
			}
		}
	}

	return ret;
}

}
}
}
}
