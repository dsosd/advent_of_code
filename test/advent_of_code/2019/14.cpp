//WARNING: This file is AUTOMATICALLY generated. Changes will be OVERWRITTEN!
#include <fstream>

#include <catch2/catch.h>

#include <challenge/advent_of_code/main.h>

namespace tul{
namespace test{
namespace aoc{

TEST_CASE( "aoc/2019_14_1", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 14);
	auto answer = [&solver](std::istream& in){
		return solver->part_1(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/14_example_1");
		REQUIRE( answer(in) == "31" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/14_example_2");
		REQUIRE( answer(in) == "165" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/14_example_3");
		REQUIRE( answer(in) == "13312" );
	}

	SECTION( "example case IV" ){
		std::ifstream in("test/advent_of_code/2019/14_example_4");
		REQUIRE( answer(in) == "180697" );
	}

	SECTION( "example case V" ){
		std::ifstream in("test/advent_of_code/2019/14_example_5");
		REQUIRE( answer(in) == "2210736" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_1");
		REQUIRE( answer(in) == "399063" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_2");
		REQUIRE( answer(in) == "483766" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_3");
		REQUIRE( answer(in) == "337862" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_4");
		REQUIRE( answer(in) == "1037742" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_5");
		REQUIRE( answer(in) == "870051" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_6");
		REQUIRE( answer(in) == "892207" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_7");
		REQUIRE( answer(in) == "1185296" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_8");
		REQUIRE( answer(in) == "783895" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_9");
		REQUIRE( answer(in) == "143173" );
	}
}

TEST_CASE( "aoc/2019_14_2", "[aoc], [aoc/2019]" ){
	auto solver = challenge::aoc::load(2019, 14);
	auto answer = [&solver](std::istream& in){
		return solver->part_2(in).get_answer();
	};

	SECTION( "example case I" ){
		std::ifstream in("test/advent_of_code/2019/14_example_1");
		REQUIRE( answer(in) == "34482758620" );
	}

	SECTION( "example case II" ){
		std::ifstream in("test/advent_of_code/2019/14_example_2");
		REQUIRE( answer(in) == "6323777402" );
	}

	SECTION( "example case III" ){
		std::ifstream in("test/advent_of_code/2019/14_example_3");
		REQUIRE( answer(in) == "82892753" );
	}

	SECTION( "example case IV" ){
		std::ifstream in("test/advent_of_code/2019/14_example_4");
		REQUIRE( answer(in) == "5586022" );
	}

	SECTION( "example case V" ){
		std::ifstream in("test/advent_of_code/2019/14_example_5");
		REQUIRE( answer(in) == "460664" );
	}

	SECTION( "hidden case I" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_1");
		REQUIRE( answer(in) == "4215654" );
	}

	SECTION( "hidden case II" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_2");
		REQUIRE( answer(in) == "3061522" );
	}

	SECTION( "hidden case III" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_3");
		REQUIRE( answer(in) == "3687786" );
	}

	SECTION( "hidden case IV" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_4");
		REQUIRE( answer(in) == "1572358" );
	}

	SECTION( "hidden case V" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_5");
		REQUIRE( answer(in) == "1863741" );
	}

	SECTION( "hidden case VI" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_6");
		REQUIRE( answer(in) == "1935265" );
	}

	SECTION( "hidden case VII" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_7");
		REQUIRE( answer(in) == "1376631" );
	}

	SECTION( "hidden case VIII" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_8");
		REQUIRE( answer(in) == "1896688" );
	}

	SECTION( "hidden case IX" ){
		std::ifstream in("test/advent_of_code/2019/14_hidden_9");
		REQUIRE( answer(in) == "8845261" );
	}
}

}
}
}
