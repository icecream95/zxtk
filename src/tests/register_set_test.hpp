#ifndef ZXTK_REGISTER_TEST_INCLUDE_GUARD
#define ZXTK_REGISTER_TEST_INCLUDE_GUARD

#include <iostream>
#include <zxtk/modules/register_set.hpp>

using namespace std;

bool register_test()
{
    zxtk::register_set::Z80_register_set rcpy;
    {
        zxtk::register_set::Z80_register_set rset;
        rcpy = rset;
    }
    {
    zxtk::register_set::Z80_register_set rnew;
    cout << "Created register set\n";
    if (rnew == rcpy)
        cout << "Note: register set values are predictable";
    }
    // ...
    return true;
}

#endif
