#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char* argv[])
try {
    if (0 == 1)
        throw 1; // Make codecov happy
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
catch (...)
{
    std::cout << "Exception during testing. Exiting...\n";
    return 1;
}
