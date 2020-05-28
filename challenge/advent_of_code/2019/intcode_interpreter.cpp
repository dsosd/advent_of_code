#include "intcode_interpreter.h"

#include <exception>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

void Intcode_interpreter::load_tape(const std::vector<int>& tape_){
	tape = tape_;
}

void Intcode_interpreter::set_tape(std::size_t pos, int val){
	set(pos, val);
}

void Intcode_interpreter::set_i_ptr(std::size_t pos){
	i_ptr = pos;
}

void Intcode_interpreter::set_io(std::shared_ptr<Intcode_io> input_, std::shared_ptr<Intcode_io> output_){
	input = input_;
	output = output_;
}

void Intcode_interpreter::exec_until_halt(){
	auto exit_code = exec_until_exit();

	while (exit_code != Intcode_exit_t::halt){
		exit_code = exec_until_exit();
	}
}

Intcode_exit_t Intcode_interpreter::exec_until_exit(){
	bool exit = false;
	Intcode_exit_t exit_code;
	int rax = 0, rbx, rcx;
	rcx = rbx = rax;

	//get the mode of the index-th parameter
	auto get_mode = [](int modes, int index){
		for (int i = 0; i < index; ++i){
			modes /= 10;
		}
		return modes % 10;
	};

	while (!exit){
		int modes = get(i_ptr) / 100;

		switch (get(i_ptr) % 100){
		case 1:
			rax = get(get(i_ptr + 1), get_mode(modes, 0)) + get(get(i_ptr + 2), get_mode(modes, 1));
			set(get(i_ptr + 3), rax);
			i_ptr += 4;
			break;
		case 2:
			rax = get(get(i_ptr + 1), get_mode(modes, 0)) * get(get(i_ptr + 2), get_mode(modes, 1));
			set(get(i_ptr + 3), rax);
			i_ptr += 4;
			break;
		case 3:
			if (input->peek(rax)){
				input->pop();
			}
			else{
				exit_code = Intcode_exit_t::no_input;
				exit = true;
			}
			set(get(i_ptr + 1), rax);
			i_ptr += 2;
			break;
		case 4:
			rax = get(get(i_ptr + 1), get_mode(modes, 0));
			output->push(rax);
			i_ptr += 2;
			exit_code = Intcode_exit_t::output;
			exit = true;
			break;
		case 5:
			rax = get(get(i_ptr + 1), get_mode(modes, 0));
			if (rax){
				i_ptr = get(get(i_ptr + 2), get_mode(modes, 1));
			}
			else{
				i_ptr += 3;
			}
			break;
		case 6:
			rax = get(get(i_ptr + 1), get_mode(modes, 0));
			if (!rax){
				i_ptr = get(get(i_ptr + 2), get_mode(modes, 1));
			}
			else{
				i_ptr += 3;
			}
			break;
		case 7:
			rbx = get(get(i_ptr + 1), get_mode(modes, 0));
			rcx = get(get(i_ptr + 2), get_mode(modes, 1));
			set(get(i_ptr + 3), rbx < rcx);
			i_ptr += 4;
			break;
		case 8:
			rbx = get(get(i_ptr + 1), get_mode(modes, 0));
			rcx = get(get(i_ptr + 2), get_mode(modes, 1));
			set(get(i_ptr + 3), rbx == rcx);
			i_ptr += 4;
			break;
		case 99:
			exit_code = Intcode_exit_t::halt;
			exit = true;
			break;
		default:
			throw std::exception();
		}
	}

	return exit_code;
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

int Intcode_interpreter::get(long pos, int mode){
	switch (mode){
	case 0:
		if (pos >= tape.size()){
			throw std::exception();
		}
		return tape[pos];
	case 1:
		return pos;
	default:
		throw std::exception();
	}
}

}
}
}
}
