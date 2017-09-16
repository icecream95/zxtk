// zxtk/src/tests/test_buffer.cpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/tests/test_buffer.cpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/tests/test_buffer.cpp)

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
