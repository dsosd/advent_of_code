#include "d06.h"

#include <sstream>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2016{

D06::D06(){
	//add characters from input char range
	cb_mapper.insert_range('a', 'z');
}

Answer D06::part_1(std::istream& in){
	parse_input(in);

	std::stringstream ret;
	for (const auto& bucket: data){
		char max_key = 'a';
		for (char i = 'a'; i <= 'z'; ++i){
			if (bucket.get_val(cb_mapper, i) > bucket.get_val(cb_mapper, max_key)){
				max_key = i;
			}
		}
		ret << max_key;
	}

	return Answer(ret.str());
}

Answer D06::part_2(std::istream& in){
	parse_input(in);

	std::stringstream ret;
	for (const auto& bucket: data){
		char min_key = 'a';
		for (char i = 'a'; i <= 'z'; ++i){
			int freq = bucket.get_val(cb_mapper, i);
			if (freq && freq < bucket.get_val(cb_mapper, min_key)){
				min_key = i;
			}
		}
		ret << min_key;
	}

	return Answer(ret.str());
}

void D06::parse_input(std::istream& in){
	std::string line;

	while (std::getline(in, line)){
		lines.push_back(line);
	}

	set_data();
}

void D06::set_data(){
	//resize vector to match characters in a line
	data.resize(lines[0].size());

	for (const std::string& line: lines){
		for (std::size_t i = 0; i < line.size(); ++i){
			data[i].update(cb_mapper, line[i], 1);
		}
	}
}

}
}
}
}
