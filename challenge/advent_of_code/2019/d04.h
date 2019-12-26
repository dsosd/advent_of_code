#ifndef uuid_guard_d7ded577_accf5dfa_c6bc9483_623cec6f
#define uuid_guard_d7ded577_accf5dfa_c6bc9483_623cec6f

#include <functional>
#include <map>
#include <set>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class D04: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	void parse_input(std::istream& in);

	//digits at offset and after will be forced to the lowest valid value, e.g. digit at offset - 1
	void force_low_digits(std::size_t offset, std::string& str) const;

	int get_num_possibilities(const std::string& start_num, std::size_t offset, int curr_repeat);
	int get_total_possibilities();

	std::string init_num;
	std::string end_num;
	std::map<int, int> repeat_counts;
	std::function<bool (const std::set<int>&)> acceptable;
};

}
}
}
}

#endif // uuid_guard_d7ded577_accf5dfa_c6bc9483_623cec6f
