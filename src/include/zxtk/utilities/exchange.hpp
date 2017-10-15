#ifndef ZXTK_UTILITIES_EXCHANGE_INCLUDE_GUARD
#define ZXTK_UTILITIES_EXCHANGE_INCLUDE_GUARD

/*! \file exchange.hpp
    \brief Provides exchange if std::exchange is not avaliable

    std::exchange was added in c++14, zxtk supports c++11
*/

#include <utility>

namespace zxtk {

#if _cplusplus < 201402L
    /*! \fn exchange template<class T, class U = T> T exchange(T& obj,
                                                               U&& new_value)
      See std::exchange */
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
