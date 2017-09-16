// zxtk/src/tests/test_memory.cpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/tests/test_memory.cpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/tests/test_memory.cpp)

#include <iostream>

#include <gtest/gtest.h>

#include <zxtk/modules/memory.hpp>

using namespace std;

struct Memory : ::testing::Test {
    zxtk::memory::Memory m;
};

TEST(Memory, DefaultConstructor)
{
    cout << "Created memory\n";
}
