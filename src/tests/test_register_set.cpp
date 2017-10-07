#include <iostream>

#include <gtest/gtest.h>

#include <zxtk/modules/register_set.hpp>

using namespace std;

struct RegisterSet : ::testing::Test {
    zxtk::register_set::Z80_register_set rset;
};

TEST_F (RegisterSet, Constructor)
{
    cout << "Created register set\n";
}

TEST_F (RegisterSet, Initialisation)
{
    cout << "Checking registers are initialised properly\n";
    EXPECT_EQ(rset.a(),0xff) << "The a register is not properly initialised";
    EXPECT_EQ(rset.pc(),0x0000) << "Whoops, the pc isn't at 0!";
    // ...
}

TEST_F (RegisterSet, WordByteLinks)
{
    cout << "Checking hl is connected to h and l etc.\n";
    rset.hl() = 0x1234;
    EXPECT_NE(rset.h(),0x34) << "Whoops, wrong endian for the register set!";
    EXPECT_EQ(rset.h(),0x12) << "hl isn't linked to h";
    EXPECT_EQ(rset.l(),0x34) << "hl isn't linked to l";
}
