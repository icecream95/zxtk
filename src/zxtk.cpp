#include <zxtk/load.hpp> /* MUST be the first in include order to allow disabling modules by defining include guards */

#include <iostream>
#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/misc/zxtk_info.hpp>
#include <zxtk/utilities/buffer.hpp>
#include <zxtk/modules/register_set.hpp>

int main ()
{
    std::cout << "zxtk (ZX spectrum Tool Kit) version " << zxtk::version::version << "\n\n";
    std::cout << "SDL is ";
    #ifndef ZXTK_USING_SDL_TRUE
    std::cout << "NOT ";
    #endif
    std::cout << "enabled\n\n";
    std::cout << "The type of a byte is " << zxtk::types::names::byte_name << '\n';
    std::cout << "The type of an address is " << zxtk::types::names::pointer_name << "\n\n";
    std::cout << "The load module being used is called " << zxtk::info::load_name << "\n\n";
    return 0;
}
