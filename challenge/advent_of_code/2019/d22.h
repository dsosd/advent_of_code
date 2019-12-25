#ifndef uuid_guard_c1e61124_cd942d61_63ac2183_1892d2cc
#define uuid_guard_c1e61124_cd942d61_63ac2183_1892d2cc

#include <array>
#include <tuple>
#include <vector>

#include "../solver.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

template<typename T, typename U>
struct Mod_op{
	T addend;
	U limit_factors;
};

template<typename T>
std::pair<T, T> get_bezout_coeff(T a, T b);

class D22: public Solver{
public:
	Answer part_1(std::istream& in) override;
	Answer part_2(std::istream& in) override;
private:
	//the largest modulo we will support only needs 5 limit factors (4 for data and 1 for carry)
	constexpr static unsigned int Limit_factor_size = 5;

	//approx. big int
	typedef unsigned long Bint;
	typedef std::array<Bint, Limit_factor_size> Limit_factors;
	typedef y2019::Mod_op<Bint, Limit_factors> Mod_op;

	void setup_modulos(Bint modulo_);
	void parse_input(std::istream& in);

	//dest = src composition dest. effectively have dest applied first, then src
	void combine(const Mod_op& src, Mod_op& dest) const;
	Mod_op compose(const std::vector<Mod_op>& ops) const;

	Bint signed_modulus(long val) const;

	Bint get_factor(const Limit_factors& factors) const;
	Limit_factors get_limit_factors(Bint factor) const;

	Bint multiply(Limit_factors lhs, Bint rhs) const;
	Limit_factors multiply(const Limit_factors& lhs, const Limit_factors& rhs) const;

	Bint modulo;
	Bint limit;
	Limit_factors limit_modulos;
	Mod_op one_shuffle;
};

}
}
}
}

#endif // uuid_guard_c1e61124_cd942d61_63ac2183_1892d2cc
