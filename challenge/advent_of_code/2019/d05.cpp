#include "d05.h"

#include <iostream>
#include <memory>
#include <sstream>

#include <util/string_parser.h>

#include "intcode_interpreter.h"
#include "intcode_io.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D05::part_1(std::istream& in){
	parse_input(in);

	auto input = std::make_shared<Intcode_io>();
	auto output = std::make_shared<Intcode_io>();
	Intcode_interpreter engine;

	engine.set_io(input, output);
	//MAGIC input in spec
	input->push(1);

	engine.load_tape(tape);
	engine.exec_until_halt();

	int ret;
	while (output->peek(ret)){
		output->pop();
	}
	return Answer(ret);
}

Answer D05::part_2(std::istream& in){
	parse_input(in);

	auto input = std::make_shared<Intcode_io>();
	auto output = std::make_shared<Intcode_io>();
	Intcode_interpreter engine;

	engine.set_io(input, output);
	//MAGIC input in spec
	input->push(5);

	engine.load_tape(tape);
	engine.exec_until_halt();

	int ret;
	while (output->peek(ret)){
		output->pop();
	}
	return Answer(ret);
}

void D05::parse_input(std::istream& in){
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
