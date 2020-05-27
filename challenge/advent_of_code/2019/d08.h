#ifndef uuid_guard_96739adb_e73ec847_7adff9d1_875d377b
#define uuid_guard_96739adb_e73ec847_7adff9d1_875d377b

#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D08: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	void parse_input(std::istream& in);

	void reduce_layer(std::string& orig, const std::string& next);

	//TODO rework this so that example inputs also work
	//MAGIC dimensions of each layer
	int length = 25;
	int width = 6;
	std::vector<std::string> layers;
};

}
}
}
}

#endif // uuid_guard_96739adb_e73ec847_7adff9d1_875d377b
