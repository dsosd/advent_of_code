//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include <fstream>

#include <catch2/catch.h>

#include <challenge/advent_of_code/main.h>

namespace tul{
namespace test{
namespace aoc{

TEST_CASE( "aoc/2019_03_1", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 3);
	auto answer = [&solver](std::istream& in){
		return solver->part_1(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/03_example_1");
		REQUIRE( answer(in) == "6" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/03_example_2");
		REQUIRE( answer(in) == "159" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/03_example_3");
		REQUIRE( answer(in) == "135" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_1");
		REQUIRE( answer(in) == "260" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_2");
		REQUIRE( answer(in) == "855" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_3");
		REQUIRE( answer(in) == "870" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_4");
		REQUIRE( answer(in) == "375" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_5");
		REQUIRE( answer(in) == "258" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_6");
		REQUIRE( answer(in) == "651" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_7");
		REQUIRE( answer(in) == "731" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_8");
		REQUIRE( answer(in) == "1264" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_9");
		REQUIRE( answer(in) == "627" );
	}

	SECTION( "hidden case X" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_10");
		REQUIRE( answer(in) == "209" );
	}

	SECTION( "hidden case XI" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_11");
		REQUIRE( answer(in) == "1211" );
	}
}

TEST_CASE( "aoc/2019_03_2", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 3);
	auto answer = [&solver](std::istream& in){
		return solver->part_2(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/03_example_1");
		REQUIRE( answer(in) == "30" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/03_example_2");
		REQUIRE( answer(in) == "610" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/03_example_3");
		REQUIRE( answer(in) == "410" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_1");
		REQUIRE( answer(in) == "15479" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_2");
		REQUIRE( answer(in) == "11238" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_3");
		REQUIRE( answer(in) == "13698" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_4");
		REQUIRE( answer(in) == "14746" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_5");
		REQUIRE( answer(in) == "12304" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_6");
		REQUIRE( answer(in) == "7534" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_7");
		REQUIRE( answer(in) == "5672" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_8");
		REQUIRE( answer(in) == "37390" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_9");
		REQUIRE( answer(in) == "13190" );
	}

	SECTION( "hidden case X" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_10");
		REQUIRE( answer(in) == "43258" );
	}

	SECTION( "hidden case XI" ){
		std::ifstream in("test/advent_of_code/2019/03_hidden_11");
		REQUIRE( answer(in) == "101386" );
	}
}

}
}
}
