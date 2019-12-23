#ifndef uuid_guard_c622d261_cf65f5bb_55596896_347bf454
#define uuid_guard_c622d261_cf65f5bb_55596896_347bf454

#include <map>
#include <tuple>
#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D14: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	typedef std::vector<long> Reaction;

	void parse_input(std::istream& in);

	int get_chemical_id(const std::string& chemical);
	//first is chemical id, second is amount
	std::pair<int, long> get_chemical_amt(const std::string& str);
	std::pair<int, Reaction> get_reaction(const std::string& str);

	long get_min_ore(long fuel) const;

	std::map<std::string, int> chemical_to_id;
	std::map<int, Reaction> chemical_to_reaction;
};

}
}
}
}

#endif // uuid_guard_c622d261_cf65f5bb_55596896_347bf454
