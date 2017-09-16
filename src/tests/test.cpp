// zxtk/src/tests/test.cpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/tests/test.cpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/tests/test.cpp)

#include <iostream>

#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
