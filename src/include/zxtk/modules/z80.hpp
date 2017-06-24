#ifndef ZXTK_MODULES_Z80_INCLUDE_GUARD
#define ZXTK_MODULES_Z80_INCLUDE_GUARD

#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>

namespace zxtk
{
    namespace cpu
    {
        class Z80
        {
        public:
        protected:
            struct Default_cpu_impl
            {
                inline void nop()
                {
#ifndef ZXTK_CORRECT_TIMING
#else
                   //advance(4);
#endif
                };
            protected:
                //void advance(types::
            };
        };
    }
}

#endif
