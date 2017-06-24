cmake_minimum_required (VERSION 2.6)
project (zxtk)
message(STATUS "Configuring zxtk...")

set (ZXTK_VERSION_MAJOR 0)
set (ZXTK_VERSION_MINOR 0)
set (ZXTK_VERSION_UPDATE 0)

set (ZXTK_TYPES_BYTE "std::uint8_t" CACHE STRING "The type of a byte. It is very unlikely you will want to change this (uint8_t)")
set (ZXTK_TYPES_WORD "std::uint16_t" CACHE STRING "The type of a word. It is very unlikely you will want to change this (uint16_t)")
set (ZXTK_TYPES_POINTER "std::uintptr_t" CACHE STRING "The type of an address (all memory, not z80) (uintptr_t)")

set (INCLUDE_FILE "include.default.hpp" CACHE STRING "include.hpp file to use (is included everywhere) (include.default.hpp)")

set (LOAD_FILE "load.default.cpp" CACHE STRING "load.cpp file to use (load.default.cpp)")

set (CONFIGURE_FILE "configure.default.hpp" CACHE STRING "configure.hpp file to use (configure.default.hpp")

option(ZXTK_ENDIANNESS_CONST "Determine endianness of CPU at compile time (on)" TRUE)

option(ZXTK_Z80_CORRECT_FLAGS "Set, 3, 5, and 7 bit flags (on)" TRUE)
option(ZXTK_CORRECT_TIMING "Time operations correctly. Without this, operations will be completed on the first T state (on)" TRUE)
option(ZXTK_Z80_FASTEST "This speeds up emulation max speed, possibly breaking some programs. Note that is forces off ZXTK_Z80_CORRECT_FLAGS and ZXTK_CORRECT_TIMING. (off)" FALSE)

option(ZXTK_MULTI_THREADS "This compiles zxtk with multiple threads, possibly speeding up emulation (on)" TRUE)
option(ZXTK_BUFFER "When multiple threads are enabled, this enables a memory buffer, increasing memory usage but allowing the z80 to run ahead of the display etc (on)" TRUE)

option(USE_SDL "Enable graphical display of emulation using SDL (on)" TRUE)
option(SDL2_STATIC "Link static build of SDL into the binaries" FALSE)
# At some point, I will probably want to make the SDL2_STATIC option only appear if SDL is enabled

option(STATIC "Build zxtk libraries as static libraries" FALSE)

option(GTEST_SHARED "Force building Google Test as a shared library" FALSE)

if (GTEST_SHARED)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif ()

option(COMPILE_TESTS "Compile tests" TRUE)

set (ZXTK_USING_SDL_TRUE 0)
if (USE_SDL)
    message(STATUS "Looking for SDL...")
    set (ZXTK_USING_SDL_TRUE 1)
    find_package(SDL2 REQUIRED)
    link_directories(${SDL2_LIBRARY_DIRS})
    message(STATUS "SDL found")
endif ()
# This might seem a bit weird, but the chance of someone not wanting SDL at the moment is pretty low

set(ZXTK_VERSION "${ZXTK_VERSION_MAJOR}.${ZXTK_VERSION_MINOR}.${ZXTK_VERSION_UPDATE}")

configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_config.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_config.hpp"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_types.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_types.hpp"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_info.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_info.hpp"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_options.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_options.hpp"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/src/${CONFIGURE_FILE}"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_options.hpp"
  )

include_directories("${PROJECT_BINARY_DIR}/src/include")
include_directories ("${PROJECT_SOURCE_DIR}/src/include")

if (STATIC)
add_library(load src/${LOAD_FILE})
add_library(memory src/utilities/buffer.cpp)
add_library(cpu src/modules/z80.cpp)
else ()
add_library(load SHARED src/${LOAD_FILE})
add_library(memory SHARED src/utilities/buffer.cpp)
add_library(cpu SHARED src/modules/z80.cpp)
endif ()

add_executable(zxtk src/zxtk.cpp)

target_link_libraries (zxtk memory load cpu)

install(TARGETS zxtk memory load cpu
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
)

if(COMPILE_TESTS)
    set(ZXTK_TEST_SOURCES
            src/tests/test.cpp
            src/tests/test_buffer.cpp
            src/tests/test_register_set.cpp
    )
    add_subdirectory(src/lib/gtest)
    include_directories(src/lib/gtest/googletest/include)
    add_executable(tests ${ZXTK_TEST_SOURCES})
    target_link_libraries(tests gtest memory)
endif ()
