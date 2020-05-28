#ifndef uuid_guard_06637e07_ef1d4df0_e34259ca_6ba95180
#define uuid_guard_06637e07_ef1d4df0_e34259ca_6ba95180

#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D02: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	void parse_input(std::istream& in);

	std::vector<int> tape;
};

}
}
}
}

#endif // uuid_guard_06637e07_ef1d4df0_e34259ca_6ba95180
