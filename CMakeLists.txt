cmake_minimum_required (VERSION 2.6)
project (zxtk)
message(STATUS "Configuring zxtk...")

set (ZXTK_VERSION_MAJOR 0)
set (ZXTK_VERSION_MINOR 1)
set (ZXTK_VERSION_UPDATE 0)
set (ZXTK_VERSION_RELEASE 1)

set (ZXTK_TYPES_BYTE "uint8_t" CACHE STRING "The type of a byte. It is very unlikely you will want to change this (uint8_t)")
set (ZXTK_TYPES_POINTER "uintptr_t" CACHE STRING "The type of an address (all memory, not z80) (uintptr_t)")
# Probably should make a way to set these without having to edit the CMakeLists

set (LOAD_FILE "load.default.cpp" CACHE STRING "load.cpp file to use (load.default.cpp)")

option(USE_SDL "Enable graphical display of emulation using SDL (TRUE)" TRUE)
option(SDL2_STATIC "Link static build of SDL into the binaries" FALSE)
# At some point, I will probably want to make the SDL2_STATIC option only appear if SDL is enabled

set (ZXTK_USING_SDL_TRUE 0)
if (USE_SDL)
    message(STATUS "Looking for SDL...")
    set (ZXTK_USING_SDL_TRUE 1)
    find_package(SDL2 REQUIRED)
    link_directories(${SDL2_LIBRARY_DIRS})
    message(STATUS "SDL found")
endif ()
# This might seem a bit weird, but the chance of someone not wanting SDL at the moment is pretty low

set(ZXTK_VERSION "${ZXTK_VERSION_MAJOR}.${ZXTK_VERSION_MINOR}.${ZXTK_VERSION_UPDATE}\(r${ZXTK_VERSION_RELEASE}\)")
configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_config.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_config.hpp"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/src/include/zxtk/misc/zxtk_types.hpp.in"
  "${PROJECT_BINARY_DIR}/src/include/zxtk/misc/zxtk_types.hpp"
  )

include_directories("${PROJECT_BINARY_DIR}/src/include")
include_directories ("${PROJECT_SOURCE_DIR}/src/include")

add_library(load src/${LOAD_FILE})
add_library(memory src/utilities/buffer.cpp)

add_executable(zxtk src/zxtk.cpp)

target_link_libraries (zxtk memory load)

add_executable(tests src/tests.cpp)

target_link_libraries (tests memory)
