/*! \mainpage zxtk
 */

#include <zxtk/load.hpp>
// MUST be the first in include order to allow disabling modules by defining
//     include guards
// This doesn't need to be first in the include order, it should be the
//     INCLUDE_FILE.

#include <iostream>

#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/misc/zxtk_info.hpp>
#include <zxtk/utilities/buffer.hpp>
#include <zxtk/modules/register_set.hpp>

// #include <boost/asio.hpp>

namespace zxtk {
    namespace core {
        int run()
        {
            std::cout << "zxtk (ZX spectrum Tool Kit) version "
                      << zxtk::version::version << "\n\n"
                      << "SDL is "
#ifndef ZXTK_USING_SDL_TRUE
                      << "NOT "
#endif
                      << "enabled\n\n"
                      << "The type of a byte is "
                      << zxtk::types::names::byte_name() << '\n'
                      << "The type of a word is "
                      << zxtk::types::names::word_name() << '\n'
                      << "The type of an address is "
                      << zxtk::types::names::pointer_name() << '\n'
                      << "The type of a cycle is "
                      << zxtk::types::names::cycle_name() << "\n\n"
                      << "The load module being used is called "
                      << zxtk::info::load_name() << '\n'
#ifdef ZXTK_Z80_FASTEST
                      << "NOTE: fast z80 option is enabled; crashes may"
                             "(will probably) occur\n"
#else
#ifndef ZXTK_Z80_CORRECT_TIMING
                      << "NOTE: correct timing is disabled. Multicolour"
                             "programs probably won't work\n"
#endif
#endif
                      << '\n';
            return 0;
        }
    }
}

int main ()
{
    try {
        return zxtk::core::run();
    }
    catch (...) {
        std::cout << "Exception caught in main. Exiting...\n\n";
        throw; // Let the OS handle the exception
    }
}
