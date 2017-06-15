#ifndef ZXTK_BUFFER_TEST_INCLUDE_GUARD
#define ZXTK_BUFFER_TEST_INCLUDE_GUARD

#include <iostream>
#include <zxtk/utilities/buffer.hpp>
#include <zxtk/misc/zxtk_types.hpp>

using namespace std;

bool buffer_test()
{
    zxtk::buffer::Buffer_store<zxtk::types::byte,1024> test;
    cout << "Created buffer\n";
    // ...
    return true;
}

#endif
