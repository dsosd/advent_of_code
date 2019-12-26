//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include "main.h"

#include "../factory.h"

#include "d03.h"
#include "d04.h"
#include "d14.h"
#include "d22.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

std::unique_ptr<Solver> load(int day){
	switch (day){
	case 3:
		{
		Factory<D03> f;
		return f.construct();
		}
	case 4:
		{
		Factory<D04> f;
		return f.construct();
		}
	case 14:
		{
		Factory<D14> f;
		return f.construct();
		}
	case 22:
		{
		Factory<D22> f;
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
