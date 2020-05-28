#include "d08.h"

#include <iostream>
#include <limits>

#include <master_h/macro/logger.h>

#include <util/char_bucket.h>
#include <util/char_bucket_mapper.h>
#include <util/string_parser.h>

#include "main.h"

namespace tul{
namespace challenge{
namespace aoc{
namespace y2019{

Answer D08::part_1(std::istream& in){
	parse_input(in);

	util::Char_bucket<3> bucket;
	util::C_bucket_mapper mapper;
	//input only has digits 0-2
	mapper.insert_range('0', '2');

	std::size_t min_layer = 0;
	int min_zeroes = std::numeric_limits<int>::max();
	for (std::size_t i = 0; i < layers.size(); ++i){
		bucket.update(mapper, layers[i]);
		int zeroes = bucket.get_val(mapper, '0');

		if (zeroes < min_zeroes){
			min_layer = i;
			min_zeroes = zeroes;
		}
		bucket.reset();
	}

	bucket.update(mapper, layers[min_layer]);
	return Answer(bucket.get_val(mapper, '1') * bucket.get_val(mapper, '2'));
}

Answer D08::part_2(std::istream& in){
	parse_input(in);

	std::string visible_layer = layers[0];
	for (auto& it: layers){
		reduce_layer(visible_layer, it);
	}

	//hardcoded OCR
	//MAGIC each letter is 5 chars long
	std::vector<unsigned int> letters(length / 5, 0);
	for (std::size_t i = 0; i < visible_layer.size(); ++i){
		auto& letter = letters[(i % length) / 5];
		letter <<= 1;
		letter |= visible_layer[i] == '1';
	}

	//MAGIC see above about length of letter
	std::string ret(length / 5, '\0');
	for (int i = 0; i < letters.size(); ++i){
		char letter = '\0';
		switch (letters[i]){
		case 422148690:
			letter = 'A';
			break;
		case 959335004:
			letter = 'B';
			break;
		case 422068812:
			letter = 'C';
			break;
		case 1024344606:
			letter = 'E';
			break;
		case 1024344592:
			letter = 'F';
			break;
		case 422074958:
			letter = 'G';
			break;
		case 623856210:
			letter = 'H';
			break;
		case 203491916:
			letter = 'J';
			break;
		case 625758866:
			letter = 'K';
			break;
		case 554189342:
			letter = 'L';
			break;
		case 959017488:
			letter = 'P';
			break;
		case 959017618:
			letter = 'R';
			break;
		case 623462988:
			letter = 'U';
			break;
		case 588583044:
			letter = 'Y';
			break;
		case 1008869918:
			letter = 'Z';
			break;
		default:
			LOG_DBUG("Unknown letter: {} @ pos {}", letters[i], i);
			for (int j = 0; j < width; ++j){
				auto temp = visible_layer.substr(j * length, length);
				temp = util::str_replace(temp, "0", " ");
				temp = util::str_replace(temp, "1", "x");
				LOG_DBUG(temp);
			}
		}
		ret[i] = letter;
	}

	return Answer(ret);
}

void D08::parse_input(std::istream& in){
	char* buf = new char[length * width + 1];

	while (in.get(buf, length * width + 1)){
		std::string temp(buf);
		if (temp.size() == length * width){
			layers.push_back(temp);
		}
	}

	delete[] buf;
}

void D08::reduce_layer(std::string& orig, const std::string& next){
	//orig adn next should both be same length since both are layers
	for (std::size_t i = 0; i < orig.size(); ++i){
		if (orig[i] == '2'){
			orig[i] = next[i];
		}
	}
}

}
}
}
}
