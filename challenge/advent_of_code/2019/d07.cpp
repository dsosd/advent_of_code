#include "d07.h"

#include <iostream>
#include <sstream>

#include <util/string_parser.h>

#include "intcode_interpreter.h"
#include "intcode_io.h"

#include <algorithm>
#include <limits>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D07::part_1(std::istream& in){
	parse_input(in);

	int max_output = std::numeric_limits<int>::min();
	//MAGIC possible phases are [0, 5)
	std::set<int> phases{0, 1, 2, 3, 4};
	//MAGIC first input is 0
	get_max_output(phases, 0, max_output);

	return Answer(max_output);
}

Answer D07::part_2(std::istream& in){
	parse_input(in);

	//MAGIC possible phases are [5, 10)
	std::vector<int> phases{5, 6, 7, 8, 9};
	//just to ensure sorted order. should be unnecessary
	std::sort(phases.begin(), phases.end());

	int max_output = std::numeric_limits<int>::min();
	do{
		//MAGIC 5 amplifiers in the spec
		std::vector<Intcode_interpreter> engines;
		engines.resize(5);
		std::vector<std::shared_ptr<Intcode_io>> buffers;

		for (std::size_t i = 0; i < engines.size(); ++i){
			buffers.push_back(std::make_shared<Intcode_io>());
		}

		for (std::size_t i = 0; i < engines.size(); ++i){
			//assign io buffers
			auto input = buffers[i];
			auto output = buffers[(i+1) % engines.size()];
			engines[i].set_io(input, output);

			engines[i].load_tape(tape);

			//add phase to input
			input->push(phases[i]);
		}

		//MAGIC add init input for first engine
		buffers[0]->push(0);

		bool running = true;
		while (running){
			running = false;
			for (auto& engine: engines){
				if (engine.exec_until_exit() != Intcode_exit_t::halt){
					running = true;
				}
			}
		}
		int output;
		while (buffers[0]->peek(output)){
			buffers[0]->pop();
		}
		max_output = std::max(output, max_output);
	}
	while(std::next_permutation(phases.begin(), phases.end()));

	return Answer(max_output);
}

void D07::parse_input(std::istream& in){
	std::stringstream ss;
	ss << in.rdbuf();
	auto parts = util::str_split(ss.str(), ",");

	tape.resize(parts.size());
	for (std::size_t i = 0; i < parts.size(); ++i){
		tape[i] = std::atoi(parts[i].c_str());
	}
}

void D07::get_max_output(std::set<int>& phases, int curr_output, int& max_output){
	if (phases.empty()){
		max_output = std::max(curr_output, max_output);
		return;
	}

	//MAGIC 5 phases ranging over [0, 5)
	for (int i = 0; i < 5; ++i){
		if (!phases.count(i)){
			continue;
		}
		phases.erase(i);

		Intcode_interpreter engine;
		engine.load_tape(tape);
		auto input = std::make_shared<Intcode_io>();
		auto output = std::make_shared<Intcode_io>();
		input->push(i);
		input->push(curr_output);
		engine.set_io(input, output);

		engine.exec_until_halt();
		int next_output;
		output->peek(next_output);

		get_max_output(phases, next_output, max_output);

		phases.insert(i);
	}
}

}
}
}
}
