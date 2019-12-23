#ifndef uuid_guard_66e90b77_fb771af0_79ea227b_83df1241
#define uuid_guard_66e90b77_fb771af0_79ea227b_83df1241

#include <memory>

namespace tul{
namespace util{

template<typename Base, typename Derived>
struct Factory{
	std::unique_ptr<Base> construct(){
		return std::unique_ptr<Base>(new Derived());
	}
};

}
}

#endif // uuid_guard_66e90b77_fb771af0_79ea227b_83df1241
