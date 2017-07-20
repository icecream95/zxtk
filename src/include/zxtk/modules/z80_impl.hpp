#ifndef ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD
#define ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD

#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/modules/register_set.hpp>

namespace zxtk {
    namespace cpu {
        namespace impl {
            struct Default_cpu_impl {
                // I'm not using any sort of decode logic as a jump table is faster - the modern day equivalent to jp (hl) is faster than jp (hl), some bit decode stuff, and another jp, and a pointer decode (on register access)
                // I'm not using a table for memory, obviously!
                void nop() // 00
                {
#ifdef ZXTK_Z80_CORRECT_TIMING
#pragma NOSUCHPRAGMA NOTE: Correct timing feature has not been implemented yet, falling back to incorrect time. This will cause multicolour programs, and some others, to not work correctly
#endif
                    ++r.pc();
                    clock(4); // NOTE: Not the c function! See protected part of class definition
                    // How about a syntax like this?
                    // clock(m1);
                }
                void ld_bc_nn() // 01
                {
                    // r.bc() = m.c.p16(r.pc());
                    // Is the m.c.xx syntax good (Memory.Const.operation)?
                    // How about m.c16 and m.g16? 
                    r.pc() += 3;
                    clock(10);
                    // clock(m1,mem,mem);
                }
                void ld_addr_bc_a() // 02
                {
                    // m.p8(r.bc()) = r.a();
                    ++r.pc();
                    clock(7);
                    // clock(m1,mem);
                }
                void inc_bc() // 03
                {
                    ++r.bc();
                    ++r.pc();
                    clock(6);
                    // clock(m1_6);
                }
                void inc_b() // 04
                {
                    ++r.b();
                    r.f() & 1 | (r.b() & 168) | ((r.b()==0) & 64) | (((r.b() & 24)==16) & 16);
                    ++r.pc();
                    clock(4);
                    // clock(m1);
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
