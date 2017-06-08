#include <iostream>
#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/utilities/buffer.hpp>
#include <zxtk/modules/register_set.hpp>
#include <zxtk/load.hpp>

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
    return 0;
}
