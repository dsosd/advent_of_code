#include "d02.h"

#include <exception>
#include <iostream>
#include <sstream>

#include <util/string_parser.h>

#include "intcode_interpreter.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D02::part_1(std::istream& in){
	parse_input(in);

	Intcode_interpreter engine;
	engine.load_tape(tape);

	//TODO somehow allow examples to work as well
	//only for non-examples
	engine.set_tape(1, 12);
	engine.set_tape(2, 2);

	engine.exec_until_halt();

	return Answer(engine.get_tape()[0]);
}

Answer D02::part_2(std::istream& in){
	parse_input(in);

	Intcode_interpreter engine;
	for (int i = 0; i < 100; ++i){
		for (int j = 0; j < 100; ++j){
			//set the tape to trial values
			engine.load_tape(tape);
			engine.set_tape(1, i);
			engine.set_tape(2, j);
			//reset instruction pointer
			engine.set_i_ptr(0);

			engine.exec_until_halt();

			//MAGIC output value specified in spec
			if (engine.get_tape()[0] == 19690720){
				return Answer(100 * i + j);
			}
		}
	}

	throw std::exception();
}

void D02::parse_input(std::istream& in){
	std::stringstream ss;
	ss << in.rdbuf();
	auto parts = util::str_split(ss.str(), ",");

	tape.resize(parts.size());
	for (std::size_t i = 0; i < parts.size(); ++i){
		tape[i] = std::atoi(parts[i].c_str());
	}
}

}
}
}
}
