//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include <fstream>

#include <catch2/catch.h>

#include <challenge/advent_of_code/main.h>

namespace tul{
namespace test{
namespace aoc{

TEST_CASE( "aoc/2019_07_1", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 7);
	auto answer = [&solver](std::istream& in){
		return solver->part_1(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/07_example_1");
		REQUIRE( answer(in) == "43210" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/07_example_2");
		REQUIRE( answer(in) == "54321" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/07_example_3");
		REQUIRE( answer(in) == "65210" );
	}

	SECTION( "example case IV" ){
		std::ifstream in("test/advent_of_code/2019/07_example_4");
		REQUIRE( answer(in) == "~ ~NO ANSWER REGISTERED~ ~" );
	}

	SECTION( "example case V" ){
		std::ifstream in("test/advent_of_code/2019/07_example_5");
		REQUIRE( answer(in) == "~ ~NO ANSWER REGISTERED~ ~" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_1");
		REQUIRE( answer(in) == "95757" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_2");
		REQUIRE( answer(in) == "17440" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_3");
		REQUIRE( answer(in) == "844468" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_4");
		REQUIRE( answer(in) == "20413" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_5");
		REQUIRE( answer(in) == "398674" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_6");
		REQUIRE( answer(in) == "255590" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_7");
		REQUIRE( answer(in) == "21760" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_8");
		REQUIRE( answer(in) == "24625" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_9");
		REQUIRE( answer(in) == "38500" );
	}
}

TEST_CASE( "aoc/2019_07_2", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 7);
	auto answer = [&solver](std::istream& in){
		return solver->part_2(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/07_example_1");
		REQUIRE( answer(in) == "~ ~NO ANSWER REGISTERED~ ~" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/07_example_2");
		REQUIRE( answer(in) == "~ ~NO ANSWER REGISTERED~ ~" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/07_example_3");
		REQUIRE( answer(in) == "~ ~NO ANSWER REGISTERED~ ~" );
	}

	SECTION( "example case IV" ){
		std::ifstream in("test/advent_of_code/2019/07_example_4");
		REQUIRE( answer(in) == "139629729" );
	}

	SECTION( "example case V" ){
		std::ifstream in("test/advent_of_code/2019/07_example_5");
		REQUIRE( answer(in) == "18216" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_1");
		REQUIRE( answer(in) == "4275738" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_2");
		REQUIRE( answer(in) == "27561242" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_3");
		REQUIRE( answer(in) == "4215746" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_4");
		REQUIRE( answer(in) == "3321777" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_5");
		REQUIRE( answer(in) == "39431233" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_6");
		REQUIRE( answer(in) == "58285150" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_7");
		REQUIRE( answer(in) == "69816958" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_8");
		REQUIRE( answer(in) == "36497698" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/07_hidden_9");
		REQUIRE( answer(in) == "33660560" );
	}
}

}
}
}
