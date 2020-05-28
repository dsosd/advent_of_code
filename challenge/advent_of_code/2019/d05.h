#ifndef uuid_guard_d584fcc6_01422313_74999ff3_7884d9ba
#define uuid_guard_d584fcc6_01422313_74999ff3_7884d9ba

#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D05: public Solver{
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

#endif // uuid_guard_d584fcc6_01422313_74999ff3_7884d9ba
