#ifndef uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379
#define uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379

#include <array>

#include "char_bucket_mapper.h"

namespace tul{
namespace util{

template<std::size_t size>
class Char_bucket{
public:
	Char_bucket();

	bool update(C_bucket_mapper& mapper, char key, int delta);

	int get_val(C_bucket_mapper& mapper, char key) const;
private:
	std::array<int, size> data;
};

template<std::size_t size>
Char_bucket<size>::Char_bucket(){
	for (auto& it: data){
		it = 0;
	}
}

template<std::size_t size>
bool Char_bucket<size>::update(C_bucket_mapper& mapper, char key, int delta){
	data[mapper.get_index(key)] += delta;
}

template<std::size_t size>
int Char_bucket<size>::get_val(C_bucket_mapper& mapper, char key) const{
	return data[mapper.get_index(key)];
}

}
}

#endif // uuid_guard_86d04edc_cbdae149_fb9cd9ff_8e31d379
