#ifndef ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD
#define ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD

#include <utility>
#include <zxtk/misc/zxtk_types.hpp>

namespace zxtk
{
    namespace register_set
    {
        class z80_register_set
        {
        public:
            // WARNING: THIS IS NOT THREAD SAFE. WRITING TO THIS FROM SOMETHING OTHER THAN THE CPU OR I/O IS NOT RECOMMENDED
            types::byte a() const {return st_af >> 8;}
            types::byte b() const {return st_bc >> 8;}
            types::byte d() const {return st_de >> 8;}
            types::byte h() const {return st_hl >> 8;}
            types::byte ixh() const {return st_ix >> 8;}
            types::byte iyh() const {return st_iy >> 8;}
            types::byte f() const {return st_af & 256;}
            types::byte c() const {return st_bc & 256;}
            types::byte e() const {return st_de & 256;}
            types::byte l() const {return st_hl & 256;}
            types::byte ixl() const {return st_ix & 256;}
            types::byte iyl() const {return st_iy & 256;}
            void a(types::byte n) {st_af = (st_af & 256) + (n << 8);}
            void b(types::byte n) {st_bc = (st_bc & 256) + (n << 8);}
            void d(types::byte n) {st_de = (st_de & 256) + (n << 8);}
            void h(types::byte n) {st_hl = (st_hl & 256) + (n << 8);}
            void ixh(types::byte n) {st_ix = (st_ix & 256) + (n << 8);}
            void iyh(types::byte n) {st_iy = (st_iy & 256) + (n << 8);}
            void f(types::byte n) {st_af = (st_af & 65280) + n;}
            void c(types::byte n) {st_bc = (st_bc & 65280) + n;}
            void e(types::byte n) {st_de = (st_de & 65280) + n;}
            void l(types::byte n) {st_hl = (st_hl & 65280) + n;}
            void ixl(types::byte n) {st_ix = (st_ix & 65280) + n;}
            void ixy(types::byte n) {st_iy = (st_iy & 65280) + n;}
            types::word af() const {return st_af;}
            types::word bc() const {return st_bc;}
            types::word de() const {return st_de;}
            types::word hl() const {return st_hl;}
            types::word ix() const {return st_ix;}
            types::word iy() const {return st_iy;}
            void af(types::word n) {st_af=n;}
            void bc(types::word n) {st_bc=n;}
            void de(types::word n) {st_de=n;}
            void hl(types::word n) {st_hl=n;}
            void ix(types::word n) {st_ix=n;}
            void iy(types::word n) {st_iy=n;}
            types::word pc() const {return st_pc;}
            types::word sp() const {return st_sp;}
            void pc(types::word n) {st_pc=n;}
            void sp(types::word n) {st_sp=n;}
            types::word ex_af(types::word n) {return std::exchange(st_af,n);}
            types::word ex_bc(types::word n) {return std::exchange(st_bc,n);}
            types::word ex_de(types::word n) {return std::exchange(st_de,n);}
            types::word ex_hl(types::word n) {return std::exchange(st_hl,n);}
            types::word ex_ix(types::word n) {return std::exchange(st_ix,n);}
            types::word ex_iy(types::word n) {return std::exchange(st_iy,n);}
            types::word ex_pc(types::word n) {return std::exchange(st_pc,n);}
            types::word ex_sp(types::word n) {return std::exchange(st_sp,n);}
            void ex_af_af() {std::swap(st_af,sta_af);}
            void exx() {std::swap(st_bc,sta_bc);std::swap(st_de,sta_de);std::swap(st_hl,sta_hl);}
            void ex_de_hl() {std::swap(st_de,st_hl);}
        private:
            types::word st_af;
            types::word st_bc;
            types::word st_de;
            types::word st_hl;
            types::word sta_af;
            types::word sta_bc;
            types::word sta_de;
            types::word sta_hl;
            types::word st_pc;
            types::word st_sp;
            types::word st_ix;
            types::word st_iy;
        };
    }
}

#endif
