#ifndef ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD
#define ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD

#include <zxtk/utilities/exchange.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/misc/zxtk_config.hpp>
#include <utility>
#include <cstddef>

namespace zxtk {
    namespace register_set {
        namespace impl
        {
#ifdef ZXTK_ENDIANNESS_COMPILE_TIME_CHECK
            constexpr 
#endif
            types::byte little_endian()
            {
                return ((std::uint16_t{1}>>8)>0)?0:1;
            }
#ifdef ZXTK_ENDIANNESS_COMPILE_TIME_CHECK
            constexpr
#endif
            types::byte big_endian()
            {
                return ((std::uint16_t{1}>>8)>0)?1:0;
            }
        }
        class Z80_register_set
        {
        public:
            Z80_register_set():st_af{0xffff},st_pc{0x0000} {}

            // Most Z80 registers are not initialised, but they are initialised
            // anyway (af and sp are set to ffff on startup and pc, iffs and iv
            // are 0). We could add in realistic values where compilation flags
            // (to simulate different z80's), time since last use and other things
            // but really, I don't know of any use of this. Submit an issue if you
            // want this feature

            // Flags (low bits first) carry, add/sub, parity, bit 3, half-carry, bit 5, zero, sign

            // WARNING: THIS IS NOT THREAD SAFE. WRITING TO THIS FROM SOMETHING OTHER THAN THE CPU OR I/O IS NOT RECOMMENDED
            types::byte& a() {return *(reinterpret_cast<types::byte*>(&st_af)+impl::little_endian());}
            types::byte& f() {return *(reinterpret_cast<types::byte*>(&st_af)+impl::big_endian());}
            types::byte& b() {return *(reinterpret_cast<types::byte*>(&st_bc)+impl::little_endian());}
            types::byte& c() {return *(reinterpret_cast<types::byte*>(&st_bc)+impl::big_endian());}
            types::byte& d() {return *(reinterpret_cast<types::byte*>(&st_de)+impl::little_endian());}
            types::byte& e() {return *(reinterpret_cast<types::byte*>(&st_de)+impl::big_endian());}
            types::byte& h() {return *(reinterpret_cast<types::byte*>(&st_hl)+impl::little_endian());}
            types::byte& l() {return *(reinterpret_cast<types::byte*>(&st_hl)+impl::big_endian());}
            types::byte& ixh() {return *(reinterpret_cast<types::byte*>(&st_ix)+impl::little_endian());}
            types::byte& ixl() {return *(reinterpret_cast<types::byte*>(&st_ix)+impl::big_endian());}
            types::byte& iyh() {return *(reinterpret_cast<types::byte*>(&st_iy)+impl::little_endian());}
            types::byte& iyl() {return *(reinterpret_cast<types::byte*>(&st_iy)+impl::big_endian());}
            types::word& af() {return st_af;}
            types::word& bc() {return st_bc;}
            types::word& de() {return st_de;}
            types::word& hl() {return st_hl;}
            types::word& ix() {return st_ix;}
            types::word& iy() {return st_iy;}
            types::word& sp() {return st_sp;}
            types::word& pc() {return st_pc;}
            types::byte& i() {return st_i;}
            types::byte& r() {return st_r;}
            bool& iff1() {return st_iff1;}
            bool& iff2() {return st_iff2;}
            void exx() {std::swap(st_bc,st_bc_a);std::swap(st_de,st_de_a);std::swap(st_hl,st_hl_a);}
            void ex_af_af() {std::swap(st_af, st_af_a);}
            // const versions
            types::byte a() const {return *(reinterpret_cast<const types::byte*>(&st_af)+impl::little_endian());}
            types::byte f() const {return *(reinterpret_cast<const types::byte*>(&st_af)+impl::big_endian());}
            types::byte b() const {return *(reinterpret_cast<const types::byte*>(&st_bc)+impl::little_endian());}
            types::byte c() const {return *(reinterpret_cast<const types::byte*>(&st_bc)+impl::big_endian());}
            types::byte d() const {return *(reinterpret_cast<const types::byte*>(&st_de)+impl::little_endian());}
            types::byte e() const {return *(reinterpret_cast<const types::byte*>(&st_de)+impl::big_endian());}
            types::byte h() const {return *(reinterpret_cast<const types::byte*>(&st_hl)+impl::little_endian());}
            types::byte l() const {return *(reinterpret_cast<const types::byte*>(&st_hl)+impl::big_endian());}
            types::byte ixh() const {return *(reinterpret_cast<const types::byte*>(&st_ix)+impl::little_endian());}
            types::byte ixl() const {return *(reinterpret_cast<const types::byte*>(&st_ix)+impl::big_endian());}
            types::byte iyh() const {return *(reinterpret_cast<const types::byte*>(&st_iy)+impl::little_endian());}
            types::byte iyl() const {return *(reinterpret_cast<const types::byte*>(&st_iy)+impl::big_endian());}
            types::word af() const {return st_af;}
            types::word bc() const {return st_bc;}
            types::word de() const {return st_de;}
            types::word hl() const {return st_hl;}
            types::word ix() const {return st_ix;}
            types::word iy() const {return st_iy;}
            types::word sp() const {return st_sp;}
            types::word pc() const {return st_pc;}
            types::byte i() const {return st_i;}
            types::byte r() const {return st_r;}
            bool iff() const {return st_iff1;}
            types::byte get_im() const {return st_im;}
            void store_im(types::byte b) {switch(b){case 0: case 1: case 2: st_im = b;default:;}}
        protected:
            types::word st_af {0xffff};
            types::word st_bc {0xffff};
            types::word st_de {0xffff};
            types::word st_hl {0xffff};
            types::word st_af_a {0xffff};
            types::word st_bc_a {0xffff};
            types::word st_de_a {0xffff};
            types::word st_hl_a {0xffff};
            types::word st_pc {0x0000};
            types::word st_sp {0xffff};
            types::word st_ix {0xffff};
            types::word st_iy {0xffff};
            types::byte st_r {0xff};
            types::byte st_i {0xff};
            types::byte st_im {0x00};
            bool st_iff1 {0};
            bool st_iff2 {0};
        };
    }
}

#endif
