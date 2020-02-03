#include "answer.h"

#include <sstream>

namespace tul{
namespace challenge{
namespace aoc{

Answer::Answer(){
}

Answer::Answer(long answer_){
	std::stringstream ss;
	ss << answer_;
	answer = ss.str();
}

Answer::Answer(const std::string& str){
	answer = str;
}

const std::string& Answer::get_answer() const{
	return answer;
}

}
}
}
