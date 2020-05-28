#ifndef uuid_guard_06637e07_ef1d4df0_e34259ca_6ba95180
#define uuid_guard_06637e07_ef1d4df0_e34259ca_6ba95180

#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class Intcode_interpreter{
public:
	void load_tape(const std::vector<int>& tape_);
	void set_tape(std::size_t pos, int val);

	void set_i_ptr(std::size_t pos);

	void exec_until_halt();

	const std::vector<int>& get_tape() const;
private:
	void set(std::size_t pos, int val);
	int get(std::size_t pos);

	std::size_t i_ptr = 0;
	std::vector<int> tape;
};

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
