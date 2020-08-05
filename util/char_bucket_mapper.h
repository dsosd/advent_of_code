#include <master_h/all.h>

#ifndef uuid_guard_dd47e170_60949cb6_bf10998e_911fbeb6
#define uuid_guard_dd47e170_60949cb6_bf10998e_911fbeb6

#include <map>

namespace tul{
namespace util{

class C_bucket_mapper{
public:
	bool insert_char(char val);
	bool insert_range(char start, char end);

	int get_index(char val) const;
private:
	std::map<char, int> mapper;
};

}
}

#endif // uuid_guard_dd47e170_60949cb6_bf10998e_911fbeb6
