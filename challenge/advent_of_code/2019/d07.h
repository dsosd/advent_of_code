#ifndef uuid_guard_4c0e3ed4_cd3dcd32_8e4e265b_71e28970
#define uuid_guard_4c0e3ed4_cd3dcd32_8e4e265b_71e28970

#include <set>
#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D07: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	void parse_input(std::istream& in);

	void get_max_output(std::set<int>& phases, int curr_output, int& max_output);

	std::vector<int> tape;
};

}
}
}
}

#endif // uuid_guard_4c0e3ed4_cd3dcd32_8e4e265b_71e28970
