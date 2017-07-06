#ifndef ZXTK_MODULES_MEMORY_INCLUDE_GUARD
#define ZXTK_MODULES_MEMORY_INCLUDE_GUARD

#include <array>

#include <zxtk/utilities/buffer.hpp>
#include <zxtk/misc/zxtk_types.hpp>

namespace zxtk {
    namespace memory {
        template<typename M = types::pointer, typename B = types::cycle>
        class Memory_array { // TODO
        };

        class Memory_array_spectrum { // TODO
        };

        template<types::pointer S>
        class Basic_memory_array_test { // TODO: Remove this when Memory_Array is done
        public:
            wtite
        protected:
            array<types::byte,S>;
        };

        template<typename A = Memory_array>
        class Memory {
        public:
        private:
            A m;
        }
    }
}

#endif
