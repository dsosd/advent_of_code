#include "intcode_io.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Intcode_io::Intcode_io(){
	mutex = std::make_unique<std::mutex>();
}

void Intcode_io::push(int val){
	mutex->lock();
	data.push(val);
	mutex->unlock();
}

bool Intcode_io::peek(int& ret){
	std::lock_guard<std::mutex> lock(*mutex);

	if (data.empty()){
		return false;
	}
	ret = data.front();
	return true;
}

void Intcode_io::pop(){
	mutex->lock();
	data.pop();
	mutex->unlock();
}

}
}
}
}
