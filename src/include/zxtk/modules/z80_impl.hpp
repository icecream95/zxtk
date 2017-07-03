#ifndef ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD
#define ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD

#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/modules/register_set.hpp>

namespace zxtk {
    namespace cpu {
        namespace impl {
            struct Default_cpu_impl {
                void nop() // 00
                {
#ifdef ZXTK_Z80_CORRECT_TIMING
#pragma NOSUCHPRAGMA NOTE: Correct timing feature has not been implemented yet, falling back to incorrect time. This will cause multicolour programs, and some others, to not work correctly
#endif
                    ++r.pc();
                    clock(4);
                }
                void ld_bc_nn() // 01
                {
                    // r.bc() = m.p16(r.pc());
                    r.pc() += 3;
                    clock(10);
                }
            protected:
                
                register_set::Z80_register_set r;
                // memory::Memory m;
                types::cycle diff_cycle (types::cycle a, types::cycle b) {return 0;} // TODO
                types::cycle cycle {0}; // NOTE: It feels wrong making this and the next declaration a member of this class (and not its base). Any ideas on how to do this better?
                types::cycle mcycle() { /*...*/ return 0;} // TODO
                void clock(types::cycle i)
                    {
#ifdef ZXTK_THREADS_TRUE
                        if (diff_cycle(mcycle(),cycle)>i)
                            cycle += i;
#else
#error Single thread excectuion has not been implemented yet
// TODO: Implement single thread excectuion
#endif
                    }
            };
        }
    }
}
#endif
