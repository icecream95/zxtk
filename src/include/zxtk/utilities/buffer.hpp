#ifndef ZXTK_UTILITIES_BUFFER_INCLUDE_GUARD
#define ZXTK_UTILITIES_BUFFER_INCLUDE_GUARD

#include <array>
#include <queue>
#include <limits>
#include <utility>
#include <zxtk/misc/zxtk_types.hpp>
#include <zxtk/utilities/utilities.hpp>

namespace zxtk { // Should this be in here?
    namespace buffer {
        // Should the priority type be templated? What about the tick type
        template<typename T, typename L = unsigned long long, typename P = int>
        class Buf_access_info {
        public:
            template<typename N>
            bool operator<(const Buf_access_info<T,L,N>& b) const
            {
                return use_tick > b.use_tick || (use_tick == b.use_tick && priority > b.priority);
                // Note the switch around - the earlier a Buf_access_info is going to be used, the higher the comparative value
            }
            template<typename N>
            bool operator==(const Buf_access_info<T,L,N>& b) const
            {
                return use_tick == b.use_tick && data == b.data && addr == b.addr && priority == b.priority;
                // Should we test the priority here?
            }
            // TODO: More comparison operators
            // TODO: Constructor
        private:
            L use_tick;
            T data;
            zxtk::types::pointer addr;
            int priority;                                           // Lower priorities will be used first
        };

        template<typename T, std::size_t N, typename C = std::array<T,N>, bool O = true,
        typename L = unsigned long long, typename Q = std::priority_queue<Buf_access_info<T,L>>>
        // We need a deque to store changes that have been added but not yet synced with all the clients
        class Buffer_store {
        public:
            template<typename U, std::size_t P, typename D, bool R, typename M, typename S>
            friend class Buffer_client;

            using tick_type = L;
            // Note the absence of usual stuff like value_type
            // TODO: Make a class Buffer_timepoint for giving data to
            //     things that don't know about timing
            constexpr static L max_tick_diff = std::numeric_limits<L>::max()/2;
            // Should write operations be avaliable here or should we
            //     require making a Buffer_user class or something
            //     like that?
            // The latter has the advantage of being able to optimise
            //     the case where there is only one user with write
            //     access (which is quite common) but has a small
            //     memory footprint. The problem with this
            //     optimisation is that there is either a performance,
            //     memory or features disadvantage.
        private:
            bool read_only {false};
            tick_type current_tick {0};
            bool tick_was_over {false};
            C data;  // C defaults to an array<T,N>
            Q queue; // Q defaults to a priority_queue<Buf_access_info<T,L>>
        };

        template<typename T, std::size_t N, typename C = std::array<T,N>, bool O = true,
                 typename L = unsigned long long, typename Q = std::priority_queue<Buf_access_info<T,L>>>
        // We should store a cache of the array at the current tick so if
        //     monitoring devices which are slow are attached, the global tick
        //     won't have to wait, just pass the popped entries from the
        //     priority_queue, possibly into a deque, and store a slowest tick
        //     value in the buffer_store. A depue would be better than a normal
        //     queue as none of the "slow" clients would have to wait for each
        //     other.
        class Buffer_client {
        public:
            Buffer_client(Buffer_store<T, N, C, O, L, Q>);
            // There will be multiple types of Buffer_store, such as a Buffer_slice and Buffer_multi [possibly with other names],
            //     so we should allow these. Should a wrapper class or std::variant be used?
        };


        template<typename T, std::size_t N, typename C = std::array<T,N>, bool O = true,
                 typename L = unsigned long long, typename Q = std::priority_queue<Buf_access_info<T,L>>>
        Buffer_client<T, N, C, O, L, Q> make_buffer(Buffer_store<T, N, C, O, L, Q>& s)
        {
            return {s};
        }
    }
}
#endif
