//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include "main.h"

#include "../factory.h"

#include "d06.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2016{

std::unique_ptr<Solver> load(int day){
	switch (day){
	case 6:
		{
		Factory<D06> f;
		return f.construct();
		}
	default:
		return nullptr;
	}
}

}
}
}
}
