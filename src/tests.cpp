#include "tests/buffer.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool bad = !buffer_test();
    if(bad)
        cout << "Tests failed!\n";
    else
        cout << "Tests completed\n";
    return bad;
}
