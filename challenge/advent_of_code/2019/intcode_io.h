#ifndef uuid_guard_d2813fb3_cc5d502f_bd40fc72_25a5bcf0
#define uuid_guard_d2813fb3_cc5d502f_bd40fc72_25a5bcf0

#include <memory>
#include <mutex>
#include <queue>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

class Intcode_io{
public:
	Intcode_io();

	void push(int val);
	bool peek(int& ret);
	void pop();
private:
	std::unique_ptr<std::mutex> mutex;
	std::queue<int> data;
};

}
}
}
}

#endif // uuid_guard_d2813fb3_cc5d502f_bd40fc72_25a5bcf0
