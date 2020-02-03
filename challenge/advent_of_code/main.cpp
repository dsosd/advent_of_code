#include "main.h"

#include "2016/main.h"
#include "2017/main.h"
#include "2019/main.h"

namespace tul{
namespace challenge{
namespace aoc{

std::unique_ptr<Solver> load(int year, int day){
	switch (year){
	case 2016:
		return y2016::load(day);
	case 2017:
		return y2017::load(day);
	case 2019:
		return y2019::load(day);
	default:
		return nullptr;
	}
}

}
}
}
