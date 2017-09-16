// zxtk/src/include/zxtk/utilities/exchange.hpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/include/zxtk/utilities/exchange.hpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/include/zxtk/utilities/exchange.hpp)

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
