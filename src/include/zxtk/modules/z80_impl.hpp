#ifndef ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD
#define ZXTK_MODULES_Z80_IMPLEMENTATION_INCLUDE_GUARD

#include <zxtk/misc/zxtk_config.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/modules/register_set.hpp>
#include <zxtk/modules/memory.hpp>

namespace zxtk {
    namespace cpu {
        namespace impl {
            template <typename M = memory::Memory, typename R = register_set::Z80_register_set>
            struct Default_cpu_impl {
                // I'm not using any sort of decode logic as a jump table is faster - the modern day equivalent to jp (hl) is faster than jp (hl), some bit decode stuff, and another jp, and a pointer decode (on register access)
                // I'm not using a table for memory, obviously!
                using memory_type = M;
                using register_type = R;
                                        // oct (hex)
                void nop()              // 000 (00)
                {
#ifdef ZXTK_Z80_CORRECT_TIMING
#pragma NOSUCHPRAGMA NOTE: Correct timing feature has not been implemented yet, falling back to incorrect time. This will cause multicolour programs, and some others, to not work correctly
#endif
                    ++r.pc();
                    clock(4); // NOTE: Not the c function! See protected part of class definition
                    // How about a syntax like this?
                    // clock(m1);
                }
                void ld_bc_nn()         // 001 (01)
                {
                    r.bc() = m.g16(++r.pc());
                    r.pc() += 2;
                    clock(10);
                    // clock(m1,mem,mem);
                }
                void ld_addr_bc_a()     // 002 (02)
                {
                    m.r8(r.bc()) = r.a();
                    ++r.pc();
                    clock(7);
                    // clock(m1,mem);
                }
                void inc_bc()           // 003 (03)
                {
                    ++r.bc();
                    ++r.pc();
                    clock(6);
                    // clock(m1_6);
                }
                void inc_b()            // 004 (04)
                {
                    ++r.b();
                    // flagaffect (inc,r.b(),254);
                    // ^~~~~~~~~~ any ideas for a better name for this function?
                    // The 254 is 11111110, or all the flags this instruction affects
                    ++r.pc();
                    clock(4);
                    // clock(m1);
                }
                void dec_b()            // 005 (05)
                {
                    --r.b();
                    // flagaffect (dec,r.b(),254);
                    ++r.pc();
                    clock(4);
                    // clock(m1);
                }
                void ld_b_n()           // 006 (06)
                {
                    r.b() = m.g8(++r.pc());
                    ++r.pc();
                    clock(7);
                    // clock(m1,mem);
                }
                void rlca()             // 007 (07)
                {
                    // flagand (196);
                    // flagcalc (1);
                    // TODO: We need a Flag class for all this
                    bool tmp = r.f() & 1;
                    r.f() &= 254 | (((r.a() & 128) == 128)?1:0);
                    r.a() <<= 1;
                    r.a() |= tmp;
                    ++r.pc();
                    clock(4);
                }
                void ex_af_alt_af()     // 010 (08)
                {
                    r.ex_af_af();
                    ++r.pc();
                    clock(4);
                }
                void add_hl_bc()        // 011 (09)
                {
                    r.hl() += r.bc();
                    // Flags: C,N,H
                    ++r.pc();
                    clock(11);
                }
                void ld_a_addr_bc()     // 012 (0A)
                {
                    r.a() = m.g8(r.bc());
                    ++r.pc()
                    clock(7);
                }
                void dec_bc()           // 013 (0B)
                {
                    --r.bc();
                    ++r.pc();
                    clock(6);
                    // clock(m1_6);
                }
                void inc_c()            // 014 (0C)
                {
                    ++r.c();
                    // flagaffect (inc,r.c(),254);
                    // ^~~~~~~~~~ any ideas for a better name for this function?
                    // The 254 is 11111110, or all the flags this instruction affects
                    ++r.pc();
                    clock(4);
                    // clock(m1);
                }
                void dec_c()            // 015 (0D)
                {
                    --r.c();
                    // flagaffect (dec,r.c(),254);
                    ++r.pc();
                    clock(4);
                    // clock(m1);
                }
                void ld_c_n()           // 016 (0E)
                {
                    r.c() = m.g8(++r.pc());
                    ++r.pc();
                    clock(7);
                    // clock(m1,mem);
                }
                void rrca()             // 017 (0F)
                {
                    // flagand (196);
                    // flagcalc (1);
                    // TODO: We need a Flag class for all this
                    bool tmp = r.f() & 1;
                    r.f() &= 254 | r.a() & 1;
                    r.a() >>= 1;
                    r.a() |= ((tmp==1)?128:0);
                    ++r.pc();
                    clock(4);
                }
            protected:
                R r;
                M m; // Ummm, should the CPU own the memory? TODO
                types::cycle diff_cycle (types::cycle, types::cycle) {return 0;} // TODO
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
