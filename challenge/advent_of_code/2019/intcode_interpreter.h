#ifndef uuid_guard_85e2d1cd_6f335e2d_a253c2cc_635042ca
#define uuid_guard_85e2d1cd_6f335e2d_a253c2cc_635042ca

#include <memory>
#include <vector>

#include "intcode_io.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class Intcode_interpreter{
public:
	void load_tape(const std::vector<int>& tape_);
	void set_tape(std::size_t pos, int val);

	void set_i_ptr(std::size_t pos);
	void set_io(std::shared_ptr<Intcode_io> input_, std::shared_ptr<Intcode_io> output_);

	void exec_until_halt();

	const std::vector<int>& get_tape() const;
private:
	void set(std::size_t pos, int val);
	int get(long pos, int mode = 0);

	std::size_t i_ptr = 0;
	std::vector<int> tape;

	std::shared_ptr<Intcode_io> input;
	std::shared_ptr<Intcode_io> output;
};

}
}
}
}

#endif // uuid_guard_85e2d1cd_6f335e2d_a253c2cc_635042ca
