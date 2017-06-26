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
#ifdef ZXTK_Z80_CORRECT_TIMING
#pragma NOSUCHPRAGMA NOTE: Correct timing feature has not been implemented yet, falling back to incorrect time. This will cause multicolour programs, and some others, to not work correctly
#endif
                   advance(4);
                };
            protected:
                void advance(int i)
                {
                }
            };
        };
    }
}

#endif
