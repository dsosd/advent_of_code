#ifndef uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379
#define uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379

#include <array>
#include <string>

#include "char_bucket_mapper.h"

namespace tul{
namespace util{

template<std::size_t size>
class Char_bucket{
public:
	Char_bucket();

	void update(C_bucket_mapper& mapper, char key, int delta);
	void update(C_bucket_mapper& mapper, const std::string& str);
	void reset();

	int get_val(C_bucket_mapper& mapper, char key) const;
private:
	std::array<int, size> data;
};

template<std::size_t size>
Char_bucket<size>::Char_bucket(){
	reset();
}

template<std::size_t size>
void Char_bucket<size>::update(C_bucket_mapper& mapper, char key, int delta){
	data[mapper.get_index(key)] += delta;
}

template<std::size_t size>
void Char_bucket<size>::update(C_bucket_mapper& mapper, const std::string& str){
	for (char ch: str){
		update(mapper, ch, 1);
	}
}

template<std::size_t size>
void Char_bucket<size>::reset(){
	for (auto& it: data){
		it = 0;
	}
}

template<std::size_t size>
int Char_bucket<size>::get_val(C_bucket_mapper& mapper, char key) const{
	return data[mapper.get_index(key)];
}

}
}

#endif // uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379
