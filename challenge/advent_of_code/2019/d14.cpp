#include "d14.h"

#include <cmath>
#include <iostream>
#include <list>

#include <util/string_parser.h>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D14::part_1(std::istream& in){
	parse_input(in);

	//MAGIC find min ore for 1 fuel
	return Answer(get_min_ore(1));
}

Answer D14::part_2(std::istream& in){
	parse_input(in);

	//MAGIC find max fuel for 10^12 ore
	constexpr long max_ore = std::pow(10, 12);

	long min = max_ore / get_min_ore(1);
	long max = min * 2;

	while (get_min_ore(max) < max_ore){
		min = max;
		max *= 2;
	}

	while (min < max){
		long mid = (min + max) / 2;

		if (get_min_ore(mid + 1) < max_ore){
			min = mid + 1;
		}
		else{
			max = mid;
		}
	}

	return Answer(min);
}

void D14::parse_input(std::istream& in){
	std::string line;
	while (std::getline(in, line)){
		chemical_to_reaction.insert(get_reaction(line));
	}

	//make all the reactions have equal size
	for (auto& it: chemical_to_reaction){
		it.second.resize(chemical_to_id.size());
		it.second.shrink_to_fit();
	}
}

int D14::get_chemical_id(const std::string& chemical){
	if (!chemical_to_id.count(chemical)){
		//We use a -1 because the map will make the element before the size call
		chemical_to_id[chemical] = chemical_to_id.size() - 1;
	}
	return chemical_to_id[chemical];
}

std::pair<int, long> D14::get_chemical_amt(const std::string& str){
	auto parts = util::str_split(str, " ");

	return std::make_pair(get_chemical_id(parts[1]), std::stoi(parts[0]));
}

std::pair<int, D14::Reaction> D14::get_reaction(const std::string& str){
	/*Example:
	3 A, 4 B => 9 C
	\Side 0/    \ /
	\ /  \ /    |Side 1
	|Part 0     |Part 0
	     |Part 1
	*/
	auto sides = util::str_split(str, " => ");
	Reaction ret;
	int output_chemical = 0;

	//auto resize when space is needed
	auto resize = [&ret](std::size_t index){
		if (ret.size() < index + 1){
			//resize at least double the space or if that is too low, just enough for the index
			ret.resize(std::max(2 * ret.size(), index + 1));
		}
	};

	//0 for lhs - input chemicals
	//1 for rhs - output chemicals
	for (int i = 0; i <= 1; ++i){
		auto parts = util::str_split(sides[i], ", ");
		for (const auto& part: parts){
			auto temp = get_chemical_amt(part);
			resize(temp.first);
			//-1 for input (missing) and 1 for output (excess)
			ret[temp.first] = (i ? 1 : -1) * temp.second;

			//guaranteed only one output chemical
			if (i == 1){
				output_chemical = temp.first;
			}
		}
	}

	return std::make_pair(output_chemical, ret);
}

long D14::get_min_ore(long fuel) const{
	//queue of reactions to process, using a list to allow iterator access
	std::list<int> queue;
	for (std::size_t i = 0; i < chemical_to_id.size(); ++i){
		queue.push_back(i);
	}

	//negative means missing, positive means excess
	std::vector<long> required_amts(chemical_to_id.size());
	required_amts[chemical_to_id.at("FUEL")] = -1 * fuel;

	while (queue.size()){
		bool dependency = false;
		int chemical = queue.front();

		if (chemical == chemical_to_id.at("ORE")){
			dependency = true;
		}

		//if the current chemical is still required somewhere down the queue
		for (auto it = queue.begin(); !dependency && it != queue.end(); ++it){
			//if the corresponding reaction doesn't exist, skip it (should only happen for ORE)
			if (!chemical_to_reaction.count(*it)){
				continue;
			}
			if (chemical_to_reaction.at(*it).at(chemical) < 0){
				dependency = true;
			}
		}

		if (!dependency){
			Reaction reaction = chemical_to_reaction.at(chemical);
			long multiple = std::ceil(-1.0d * required_amts[chemical] / reaction[chemical]);

			for (std::size_t i = 0; i < reaction.size(); ++i){
				required_amts[i] += multiple * reaction[i];

				if (reaction[i] < 0){
					queue.push_back(i);
				}
			}
		}

		queue.pop_front();
	}

	return -1 * required_amts[chemical_to_id.at("ORE")];
}

}
}
}
}
