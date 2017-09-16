// zxtk/src/tests/test_cpu.cpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/tests/test_cpu.cpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/tests/test_cpu.cpp)

#include <iostream>

#include <gtest/gtest.h>

#include <zxtk/modules/z80.hpp>
#include <zxtk/modules/z80_impl.hpp>
#include <zxtk/modules/register_set.hpp>
#include <zxtk/modules/memory.hpp>

using namespace std;

struct Z80 : ::testing::Test {
    zxtk::cpu::Z80 z;
    zxtk::cpu::impl::Default_cpu_impl<zxtk::memory::Memory,zxtk::register_set::Z80_register_set> zi; // Ouch. Why is this needed? The class has default template arguments. I think that I've messed something up in the CPU side of things
};

TEST(Z80, DefaultConstructor)
{
    cout << "Created cpu\n";
}

TEST(Z80, ImplementationConstructor)
{
    cout << "Created cpu implementation object\n";
}


