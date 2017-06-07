#include "tests/buffer.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool good = buffer_test();
    if(good)
        cout << "Tests completed\n";
    else
        cout << "Tests failed!\n";
    return good;
}
