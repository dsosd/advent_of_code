#include "d03.h"

#include <cmath>
#include <exception>
#include <iostream>
#include <vector>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2017{

template<typename T>
Point2<T>::Point2()
		:x(0), y(0){
}

Answer D03::part_1(std::istream& in){
	parse_input(in);

	Point point_offset = get_corner_offset(target_num, get_layer(target_num));
	auto dist = std::abs(point_offset.x) + std::abs(point_offset.y);

	return Answer(dist);
}

Answer D03::part_2(std::istream& in){
	parse_input(in);

	//compressed terms n = 1 to n = 100 of OEIS A141481
	std::vector<int> oeis_141481 = {
		1, 0, 1, 2, 1, 5, 1, 12, 2, 1, 28, 3, 2, 63, 11, 9, 5, 157, 26, 21, 11, 385, 59, 74, 51, 26, 1011, 137, 170, 116, 59, 2572, 314, 397, 422, 289, 147, 6895, 781, 985, 1043, 713, 362, 18117, 1915, 2433, 2617, 2768, 1888, 957, 50033, 5030, 6348, 6771, 7116, 4841, 2450, 135676, 12808, 16091, 17224, 18332, 19190, 13035, 6591, 383087, 34344, 43005, 45814, 48555, 50673, 34378, 17370, 1062314, 90259, 112724, 119689, 127507, 134780, 140393, 95173, 48065, 3055829, 249291, 310702, 328851, 349086, 367814, 382221, 258858, 130654, 8657367, 676122, 840697, 886820, 938467, 993213, 1043770, 1082586, 732611
	};

	int curr_num = 0;
	for (int term: oeis_141481){
		curr_num += term;
		if (curr_num > target_num){
			return Answer(curr_num);
		}
	}

	//need more terms in the hardcoded sequence
	throw std::exception();
}

void D03::parse_input(std::istream& in){
	std::string line;
	std::getline(in, line);
	target_num = std::stol(line);
}

long D03::get_layer_max_num(int layer) const{
	if (layer == -1){
		return 0;
	}

	//seq: 1^2, 3^2, 5^2, 7^2, 9^2, 11^2, ...
	return std::pow(2*layer + 1, 2);
}

int D03::get_layer(long num) const{
	int closest_square = std::ceil(std::sqrt(num));
	closest_square += (closest_square % 2) ? 0 : 1;

	return (closest_square - 1) / 2;
}

D03::Point D03::get_corner_offset(long num, int layer) const{
	if (num == get_layer_max_num(layer)){
		Point ret;
		ret.x = layer;
		ret.y = -layer;
		return ret;
	}

	//0 is the right side, 1 is the top side
	//2 is the left side, 3 is the bottom side
	/*
	110
	2x0
	23y
	*/
	long shifted_num = num - 1 - get_layer_max_num(layer - 1);
	int side = shifted_num / (2 * layer);
	int offset = shifted_num % (2 * layer);

	Point ret;
	if (side == 0){
		ret.x = layer;
		ret.y = -layer + 1 + offset;
	}
	else if (side == 1){
		ret.x = layer - 1 - offset;
		ret.y = layer;
	}
	else if (side == 2){
		ret.x = -layer;
		ret.y = layer - 1 - offset;
	}
	else if (side == 3){
		ret.x = -layer + 1 + offset;
		ret.y = -layer;
	}
	else{
		throw std::exception();
	}

	return ret;
}

}
}
}
}
