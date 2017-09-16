// zxtk/src/include/zxtk/modules/memory.hpp
// MIT License
// Copyright (c) 2017 icecream95 (icecream95.github.io)
// Upstream URL: https://github.com/icecream95/zxtk/blob/master/src/include/zxtk/modules/memory.hpp
// (raw: https://raw.githubusercontent.com/icecream95/zxtk/master/src/include/zxtk/modules/memory.hpp)

#ifndef ZXTK_MODULES_MEMORY_INCLUDE_GUARD
#define ZXTK_MODULES_MEMORY_INCLUDE_GUARD

#include <array>

#include <zxtk/utilities/buffer.hpp>
#include <zxtk/misc/zxtk_types.hpp>

namespace zxtk {
    namespace memory {
        template<typename M = types::pointer, typename B = types::cycle>
        class Memory_array { /* TODO */ };

        class Memory_array_spectrum { /* TODO */ };

        template<types::pointer S>
        class Basic_memory_array_test { // NOTE: Remove this when Memory_Array is done
        public:
            // NOTE: The memory interface is not finalised, and will be changed long before v1.0
            std::array<types::byte,S>& get_mem() {return memory;}
            const std::array<types::byte,S>& read_mem() const {return memory;}
        protected:
            std::array<types::byte,S> memory;
        };

        //template<typename A = Memory_array<types::pointer,types::cycle>> // 48k // CHANGEME
        class Memory {
            types::byte g8 (types::pointer p) const {return m[p];}
            types::word g16 (types::pointer p) const {return *reinterpret_cast<const types::word*>(&m[p]);}
            types::byte& r8 (types::pointer p) {return m[p];}
            types::word& r16 (types::pointer p) {return *reinterpret_cast<types::word*>(&m[p]);}
        public:
        private:
            std::array<types::byte,65536> m;
            // A m;
        };
    }
}

#endif
