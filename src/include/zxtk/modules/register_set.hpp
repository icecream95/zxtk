#ifndef ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD
#define ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD

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
        private:
            types::word st_af;
            types::word st_bc;
            types::word st_de;
            types::word st_hl;
            types::word st_pc;
            types::word st_ix;
            types::word st_iy;
        };
    }
}

#endif
