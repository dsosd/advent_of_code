#include "d22.h"

#include <exception>
#include <limits>
#include <regex>

#include <iostream>

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

template<typename T>
std::pair<T, T> get_bezout_coeff(T a, T b){
	/*performs extended Euclidean algorithm for gcd, using constant space via data rotation
	a b a%b
	. . a/b
	1 0 x
	0 1 y
	*/
	bool a_neg = a < 0;
	bool b_neg = b < 0;

	a = std::abs(a);
	b = std::abs(b);

	//b must be non-zero
	if (!b){
		throw std::exception();
	}

	//MAGIC 3 columns by 4 rows
	std::vector<T> vals{
		a, 0, 1, 0,
		b, 0, 0, 1,
		0, 0, 0, 0
	};

	auto val = [&vals](int col, int row) -> T&{
		//MAGIC see above
		col %= 3;
		return vals[col * 4 + row];
	};

	//extended Euclidean algorithm
	//MAGIC start at middle column
	int i = 1;
	//end when top remainder is 0, result is stored in column i - 1
	for (; val(i, 0); ++i){
		val(i + 1, 0) = val(i - 1, 0) % val(i, 0);
		val(i + 1, 1) = val(i - 1, 0) / val(i, 0);
		val(i + 1, 2) = val(i - 1, 2) - val(i + 1, 1) * val(i, 2);
		val(i + 1, 3) = val(i - 1, 3) - val(i + 1, 1) * val(i, 3);
	}

	return std::make_pair(
		(a_neg ? -1 : 1) * val(i - 1, 2),
		(b_neg ? -1 : 1) * val(i - 1, 3)
	);
}

Answer D22::part_1(std::istream& in){
	//MAGIC by spec
	setup_modulos(10007);

	parse_input(in);

	//MAGIC find location of the 2019th card
	Bint ret = 2019;
	ret = multiply(one_shuffle.limit_factors, ret);
	ret += one_shuffle.addend;
	ret %= modulo;

	return Answer(ret);
}

Answer D22::part_2(std::istream& in){
	//MAGIC by spec;
	setup_modulos(119315717514047);
	Bint iterations = 101741582076661;

	parse_input(in);

	int bint_bits = 8 * sizeof(Bint);

	//index = k to the corresponding Mod_op for 2^k shuffles
	std::vector<Mod_op> shuffle_cache(bint_bits);
	shuffle_cache[0] = one_shuffle;

	for (int i = 1; i < shuffle_cache.size(); ++i){
		shuffle_cache[i] = shuffle_cache[i - 1];
		combine(shuffle_cache[i - 1], shuffle_cache[i]);
	}

	std::vector<Mod_op> partial_ops;
	for (int i = 0; i < bint_bits; ++i){
		if ((iterations >> i) & 1ul){
			partial_ops.push_back(shuffle_cache[i]);
		}
	}

	Mod_op combined = compose(partial_ops);
	auto addend = combined.addend;
	auto factor = get_factor(combined.limit_factors);

	//MAGIC find n-th card in the 2020th position
	Bint card = 2020;
	card = signed_modulus(long(card) - long(addend));

	auto coefficients = get_bezout_coeff(long(factor), long(modulo));
	auto inverse = signed_modulus(coefficients.first);

	auto answer = multiply(get_limit_factors(inverse), card);

	return Answer(answer);
}

void D22::setup_modulos(Bint modulo_){
	modulo = modulo_;

	limit = std::numeric_limits<Bint>::max() / modulo_;
	limit_modulos[0] = 1;

	for (std::size_t i = 1; i < limit_modulos.size(); ++i){
		limit_modulos[i] = limit * limit_modulos[i - 1];
		limit_modulos[i] %= modulo;
	}
}

void D22::parse_input(std::istream& in){
	std::regex num("-?[0-9]+");

	std::vector<Mod_op> ops;

	std::string line;
	while (std::getline(in, line)){
		std::smatch matches;
		std::regex_search(line, matches, num);

		//cut xxx
		if (line[0] == 'c'){
			//cutting by x is equivalent to subtracting x, modulo n
			auto addend = -1 * std::stol(matches[0]);
			addend = signed_modulus(addend);
			ops.push_back(Mod_op{addend, get_limit_factors(1)});
		}
		//deal into new stack
		else if (line[5] == 'i'){
			//equivalent to adding 1 then multiplying by n - 1, modulo n
			//which is equal to multiplying by n - 1 and then adding n - 1, modulo n
			ops.push_back(Mod_op{modulo - 1, get_limit_factors(modulo - 1)});
		}
		//deal with increment xxx
		else if (line[5] == 'w'){
			//equivalent to multiplying, modulo n
			auto factor = std::stol(matches[0]);
			factor = signed_modulus(factor);
			ops.push_back(Mod_op{0, get_limit_factors(factor)});
		}
		else{
			throw std::exception();
		}
	}

	one_shuffle = compose(std::vector<Mod_op>(ops.rbegin(), ops.rend()));
}

void D22::combine(const Mod_op& src, Mod_op& dest) const{
	//m_2( m_1 * k + a_1 ) + a_2 is congruent to m_3(k + a_3), where m_3 = m_2 * m_1 and a_3 = m_2 * a_1 + a_2, all modulo n
	//src has m_2 and a_2. dest has m_1 and a_1
	//calculate a_3
	dest.addend = multiply(src.limit_factors, dest.addend);
	dest.addend += src.addend;
	dest.addend %= modulo;

	//calculate m_3
	dest.limit_factors = multiply(src.limit_factors, dest.limit_factors);
}

D22::Bint D22::signed_modulus(long val) const{
	return Bint(
		((val % long(modulo)) + long(modulo)) % long(modulo)
	);
}

D22::Mod_op D22::compose(const std::vector<Mod_op>& ops) const{
	Mod_op ret{0, get_limit_factors(1)};

	for (auto it = ops.rbegin(); it != ops.rend(); ++it){
		combine(*it, ret);
	}

	return ret;
}

D22::Bint D22::get_factor(const Limit_factors& factors) const{
	Bint ret = 0;
	for (std::size_t i = 0; i < limit_modulos.size(); ++i){
		auto temp = factors[i] * limit_modulos[i];
		temp %= modulo;
		ret += temp;
	}

	return ret % modulo;
}

D22::Limit_factors D22::get_limit_factors(Bint factor) const{
	Limit_factors ret;
	for (std::size_t i = 0; i < ret.size(); ++i){
		ret[i] = factor % limit;
		factor /= limit;
	}

	return ret;
}

D22::Bint D22::multiply(Limit_factors lhs, Bint rhs) const{
	Bint carry = 0;

	for (auto& factor: lhs){
		//modulo times limit guaranteed to be within Bint range
		factor = (factor * rhs) % modulo + carry;
		carry = factor / limit;
		factor %= limit;
	}

	//went out of bounds. increase Limit_factor_size to prevent this
	if (carry){
		throw std::exception();
	}

	return get_factor(lhs);
}

D22::Limit_factors D22::multiply(const Limit_factors& lhs, const Limit_factors& rhs) const{
	return get_limit_factors(
		multiply(lhs, get_factor(rhs))
	);
}

}
}
}
}
