//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include "main.h"

#include "../factory.h"

#include "d14.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

std::unique_ptr<Solver> load(int day){
	switch (day){
	case 14:
		{
		Factory<D14> f;
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