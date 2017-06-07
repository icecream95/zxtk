#include <iostream>
#include <zxtk/utilities/buffer.hpp>
#include <zxtk/misc/zxtk_types.hpp>

using namespace std;

bool buffer_test()
{
    zxtk::buffer::Buffer_store<uint8_t,1024> test;
    cout << "Created buffer\n";
    return true;
}
