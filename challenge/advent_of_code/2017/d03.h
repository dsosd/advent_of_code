#ifndef uuid_guard_4a07fdc8_86659d92_ae3e22c0_5de49a76
#define uuid_guard_4a07fdc8_86659d92_ae3e22c0_5de49a76

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2017{

template<typename T>
struct Point2{
	T x;
	T y;

	Point2();
};

class D03: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	typedef Point2<int> Point;

	void parse_input(std::istream& in);

	long get_layer_max_num(int layer) const;

	int get_layer(long num) const;
	Point get_corner_offset(long num, int layer) const;

	long target_num;
};

#endif // uuid_guard_4a07fdc8_86659d92_ae3e22c0_5de49a76

}
}
}
}
