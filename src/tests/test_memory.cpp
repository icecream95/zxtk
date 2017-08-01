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
