cmake_minimum_required(VERSION 3.11.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
    SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(zcm)

find_program(CCACHE_FOUND ccache)
message(STATUS "CCACHE STATUS : ${CCACHE_FOUND}")

if(CCACHE_FOUND)
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif(CCACHE_FOUND)


add_subdirectory(src)
add_subdirectory(test)
