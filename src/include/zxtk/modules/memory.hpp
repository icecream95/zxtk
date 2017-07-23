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
            // NOTE: The memory interface is not finalised, and will be changed long before v1.0
            std::array<types::byte,S>& get_mem() {return memory;}
            const std::array<types::byte,S>& read_mem() const {return memory;}
        protected:
            std::array<types::byte,S> memory;
        };

        template<typename A = Memory_array<types::pointer,types::cycle>> // 48k // CHANGEME
        class Memory {
            // n.g8 get, r, r
        public:
        private:
            A m;
        };
    }
}

#endif
