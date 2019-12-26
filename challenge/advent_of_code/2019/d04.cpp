#include "d04.h"

#include <algorithm>
#include <exception>
#include <iostream>

#include <util/string_parser.h>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D04::part_1(std::istream& in){
	parse_input(in);

	acceptable = [](const std::set<int>& repeats){
		return *(std::max_element(repeats.begin(), repeats.end())) >= 2;
	};

	return Answer(get_total_possibilities());
}

Answer D04::part_2(std::istream& in){
	parse_input(in);

	acceptable = [](const std::set<int>& repeats){
		return repeats.count(2);
	};

	return Answer(get_total_possibilities());
}

void D04::parse_input(std::istream& in){
	std::string line;
	std::getline(in, line);

	auto parts = util::str_split(line, "-");
	init_num = parts[0];
	end_num = parts[1];
}

void D04::force_low_digits(std::size_t offset, std::string& str) const{
	for (std::size_t i = offset; i < str.size(); ++i){
		str[i] = str[offset - 1];
	}
}

int D04::get_num_possibilities(const std::string& start_num, std::size_t offset, int curr_repeat){
	if (offset == start_num.size() - 1){
		repeat_counts[curr_repeat] += 1;

		std::set<int> repeats;
		for (const auto& it: repeat_counts){
			if (it.second){
				repeats.insert(it.first);
			}
		}

		repeat_counts[curr_repeat] -= 1;
		return acceptable(repeats) && start_num >= init_num ? 1 : 0;
	}

	int ret = 0;
	std::string new_start(start_num);

	//set next digit to be the same as the current
	new_start[offset + 1] = start_num[offset];
	force_low_digits(offset + 2, new_start);

	if (start_num <= new_start && new_start <= end_num){
		ret += get_num_possibilities(new_start, offset + 1, curr_repeat + 1);
	}

	//set next digit to be different from the current
	//MAGIC 9 is the last digit for base 10
	for (char i = start_num[offset] + 1; i <= '9'; ++i){
		new_start[offset + 1] = i;
		force_low_digits(offset + 2, new_start);

		if (start_num <= new_start && new_start <= end_num){
			repeat_counts[curr_repeat] += 1;
			ret += get_num_possibilities(new_start, offset + 1, 1);
			repeat_counts[curr_repeat] -= 1;
		}
	}

	return ret;
}

int D04::get_total_possibilities(){
	int ret = 0;

	//MAGIC 9 is the last digit for base 10
	for (char i = init_num[0]; i <= '9'; ++i){
		std::string new_start(init_num);
		new_start[0] = i;
		force_low_digits(1, new_start);

		ret += get_num_possibilities(new_start, 0, 1);
	}

	return ret;
}

}
}
}
}
