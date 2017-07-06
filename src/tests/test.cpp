#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
try {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
catch (...)
{
    std::cout << "Exception during testing. Exiting...\n";
    return 1;
}
