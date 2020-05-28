#include "d02.h"

#include <exception>
#include <iostream>
#include <sstream>

#include <util/string_parser.h>

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

void Intcode_interpreter::load_tape(const std::vector<int>& tape_){
	tape = tape_;
}

void Intcode_interpreter::set_tape(std::size_t pos, int val){
	set(pos, val);
}

void Intcode_interpreter::set_i_ptr(std::size_t pos){
	i_ptr = pos;
}

void Intcode_interpreter::exec_until_halt(){
	bool halt = false;
	int rax = 0;

	while (!halt){
		switch (get(i_ptr)){
		case 1:
			rax = get(get(i_ptr + 1)) + get(get(i_ptr + 2));
			set(get(i_ptr + 3), rax);
			i_ptr += 4;
			break;
		case 2:
			rax = get(get(i_ptr + 1)) * get(get(i_ptr + 2));
			set(get(i_ptr + 3), rax);
			i_ptr += 4;
			break;
		case 99:
			halt = true;
			break;
		default:
			throw std::exception();
		}
	}
}

const std::vector<int>& Intcode_interpreter::get_tape() const{
	return tape;
}

void Intcode_interpreter::set(std::size_t pos, int val){
	if (pos >= tape.size()){
		tape.resize(std::max(pos + 1, 2 * tape.size()));
	}
	tape[pos] = val;
}

int Intcode_interpreter::get(std::size_t pos){
	if (pos >= tape.size()){
		throw std::exception();
	}
	return tape[pos];
}

}
}
}
}
