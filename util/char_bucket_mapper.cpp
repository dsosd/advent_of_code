#include "char_bucket_mapper.h"

namespace tul{
namespace util{

bool C_bucket_mapper::insert_char(char val){
	if (mapper.count(val)){
		return false;
	}
	//the new element is created before .size() is called. the -1 counteracts that effect
	mapper[val] = mapper.size() - 1;
	return true;
}

bool C_bucket_mapper::insert_range(char start, char end){
	bool ret = true;

	for (char i = start; i <= end; ++i){
		ret &= insert_char(i);
	}
	return ret;
}

int C_bucket_mapper::get_index(char val) const{
	return mapper.at(val);
}

}
}
