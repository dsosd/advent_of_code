#ifndef uuid_guard_a43a56b6_303fc1eb_e81a664e_c437a63a
#define uuid_guard_a43a56b6_303fc1eb_e81a664e_c437a63a

#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

template<typename T>
struct Point2{
	T x;
	T y;

	Point2();
};

template<typename T>
struct Line{
	T p1;
	T p2;
};

class D03: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	typedef Point2<int> Point;
	typedef y2019::Line<Point> Line;

	void parse_input(std::istream& in);

	bool line_horizontal(const Line& line) const;

	Line get_line(const Point& p1, const Point& p2) const;
	bool get_close_intersect(const Line& l1, const Line& l2, Point& ret) const;
	std::vector<Point> find_intersections() const;

	std::vector<Point> path1;
	std::vector<Point> path2;
};

}
}
}
}

#endif // uuid_guard_a43a56b6_303fc1eb_e81a664e_c437a63a
