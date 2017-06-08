#include "tests/buffer_test.hpp"
#include "tests/register_set_test.hpp"
#include <iostream>

using namespace std;

int main()
{
    bool bad = !buffer_test();
    bad |= !register_test(); // Hope the compiler doesn't optimise this out!
    if(bad)
        cout << "Tests failed!\n";
    else
        cout << "Tests completed\n";
    return bad;
}
