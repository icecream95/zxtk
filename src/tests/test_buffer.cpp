#include <iostream>

#include <gtest/gtest.h>

#include <zxtk/utilities/buffer.hpp>
#include <zxtk/misc/zxtk_types.hpp>

using namespace std;

TEST(Buffer, DefaultConstructor)
{
    zxtk::buffer::Buffer_store<zxtk::types::byte,1024> buf;
    cout << "Created buffer\n";
}
