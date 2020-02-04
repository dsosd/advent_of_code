#ifndef uuid_guard_d8bee260_672e6409_1bb1b9a1_d38a0a35
#define uuid_guard_d8bee260_672e6409_1bb1b9a1_d38a0a35

#include <string>
#include <vector>

#include <util/char_bucket.h>
#include <util/char_bucket_mapper.h>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2016{

class D06: public Solver{
public:
	D06();

	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	void parse_input(std::istream& in);
	void set_data();

	//26 characters in input char range
	std::vector<util::Char_bucket<26>> data;
	util::C_bucket_mapper cb_mapper;

	std::vector<std::string> lines;
};

}
}
}
}

#endif // uuid_guard_d8bee260_672e6409_1bb1b9a1_d38a0a35
