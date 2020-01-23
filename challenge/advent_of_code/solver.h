#ifndef uuid_guard_354a3c74_da8202f2_9e4fc050_143a4f82
#define uuid_guard_354a3c74_da8202f2_9e4fc050_143a4f82

#include <iosfwd>

#include "answer.h"

namespace tul{
namespace challenge{
namespace aoc{

class Solver{
public:
	virtual ~Solver() = default;

	virtual Answer part_1(std::istream& in) = 0;
	virtual Answer part_2(std::istream& in) = 0;
};

}
}
}

#endif // uuid_guard_354a3c74_da8202f2_9e4fc050_143a4f82
