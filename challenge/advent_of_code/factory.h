#ifndef uuid_guard_d90d14dc_77224415_e23bfeb9_b5916d1f
#define uuid_guard_d90d14dc_77224415_e23bfeb9_b5916d1f

#include <util/factory.h>

#include "solver.h"

namespace tul{
namespace challenge{
namespace aoc{

template<typename T>
using Factory = util::Factory<Solver, T>;

}
}
}

#endif // uuid_guard_d90d14dc_77224415_e23bfeb9_b5916d1f
