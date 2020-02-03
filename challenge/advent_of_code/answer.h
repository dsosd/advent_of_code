#ifndef uuid_guard_4919860c_4363b2e1_3ebaaaff_dd31c5fc
#define uuid_guard_4919860c_4363b2e1_3ebaaaff_dd31c5fc

#include <string>

namespace tul{
namespace challenge{
namespace aoc{

class Answer{
public:
	Answer();
	explicit Answer(long answer_);
	explicit Answer(const std::string& str);

	const std::string& get_answer() const;
private:
	std::string answer;
};

}
}
}

#endif // uuid_guard_4919860c_4363b2e1_3ebaaaff_dd31c5fc
