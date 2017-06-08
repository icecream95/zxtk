#ifndef ZXTK_UTILITIES_EXCHANGE_INCLUDE_GUARD
#define ZXTK_UTILITIES_EXCHANGE_INCLUDE_GUARD

#include <utility>

namespace zxtk {

#if _cplusplus < 201402L

template<class T, class U = T>
T exchange(T& obj, U&& new_value)
{
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}

#else

using std::exchange;

#endif
}
#endif
