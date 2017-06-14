#ifndef ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD
#define ZXTK_UTILITIES_MODULES_REGISTER_SET_INCLUDE_GUARD

#include <zxtk/utilities/exchange.hpp>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/misc/zxtk_config.hpp>
#include <utility>
#include <cstddef>

namespace zxtk
{
    namespace register_set
    {
        namespace impl
        {
#ifdef ZXTK_ENDIANNESS_COMPILE_TIME_CHECK
            constexpr 
#endif
            types::byte little_endian()
            {
                return ((std::uint16_t{1}>>8)>0)?0:1;
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

            // WARNING: THIS IS NOT THREAD SAFE. WRITING TO THIS FROM SOMETHING OTHER THAN THE CPU OR I/O IS NOT RECOMMENDED
            types::byte& a() {return *(reinterpret_cast<types::byte*>(&st_af)+impl::little_endian());}
            types::byte& f() {return *(reinterpret_cast<types::byte*>(&st_af)+1-impl::little_endian());}
            types::byte& b() {return *(reinterpret_cast<types::byte*>(&st_bc)+impl::little_endian());}
            types::byte& c() {return *(reinterpret_cast<types::byte*>(&st_bc)+1-impl::little_endian());}
            types::byte& d() {return *(reinterpret_cast<types::byte*>(&st_de)+impl::little_endian());}
            types::byte& e() {return *(reinterpret_cast<types::byte*>(&st_de)+1-impl::little_endian());}
            types::byte& h() {return *(reinterpret_cast<types::byte*>(&st_hl)+impl::little_endian());}
            types::byte& l() {return *(reinterpret_cast<types::byte*>(&st_hl)+1-impl::little_endian());}
            types::byte& ixh() {return *(reinterpret_cast<types::byte*>(&st_ix)+impl::little_endian());}
            types::byte& ixl() {return *(reinterpret_cast<types::byte*>(&st_ix)+1-impl::little_endian());}
            types::byte& iyh() {return *(reinterpret_cast<types::byte*>(&st_iy)+impl::little_endian());}
            types::byte& iyl() {return *(reinterpret_cast<types::byte*>(&st_iy)+1-impl::little_endian());}
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
            // const versions
            types::byte a() const {return *(reinterpret_cast<const types::byte*>(&st_af)+impl::little_endian());}
            types::byte f() const {return *(reinterpret_cast<const types::byte*>(&st_af)+1-impl::little_endian());}
            types::byte b() const {return *(reinterpret_cast<const types::byte*>(&st_bc)+impl::little_endian());}
            types::byte c() const {return *(reinterpret_cast<const types::byte*>(&st_bc)+1-impl::little_endian());}
            types::byte d() const {return *(reinterpret_cast<const types::byte*>(&st_de)+impl::little_endian());}
            types::byte e() const {return *(reinterpret_cast<const types::byte*>(&st_de)+1-impl::little_endian());}
            types::byte h() const {return *(reinterpret_cast<const types::byte*>(&st_hl)+impl::little_endian());}
            types::byte l() const {return *(reinterpret_cast<const types::byte*>(&st_hl)+1-impl::little_endian());}
            types::byte ixh() const {return *(reinterpret_cast<const types::byte*>(&st_ix)+impl::little_endian());}
            types::byte ixl() const {return *(reinterpret_cast<const types::byte*>(&st_ix)+1-impl::little_endian());}
            types::byte iyh() const {return *(reinterpret_cast<const types::byte*>(&st_iy)+impl::little_endian());}
            types::byte iyl() const {return *(reinterpret_cast<const types::byte*>(&st_iy)+1-impl::little_endian());}
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
            bool iff1() const {return st_iff1;}
            bool iff2() const {return st_iff2;}
        private:
            types::word st_af;
            types::word st_bc;
            types::word st_de;
            types::word st_hl;
            types::word st_af_a;
            types::word st_bc_a;
            types::word st_de_a;
            types::word st_hl_a;
            types::word st_pc;
            types::word st_sp;
            types::word st_ix;
            types::word st_iy;
            types::byte st_r;
            types::byte st_i;
            bool st_iff1;
            bool st_iff2;
        };
    }
}

#endif