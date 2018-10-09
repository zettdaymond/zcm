cmake_minimum_required(VERSION 3.11.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.31.tar.gz"
    SHA1 "3d94b8522541c4c8eaac606f4c47d09322a8019c"
)

project(zcm)

option(ENABLE_COVERAGE_IN_DEBUG "Build code coverage report" ON)

find_program(CCACHE_FOUND ccache)
message(STATUS "CCACHE STATUS : ${CCACHE_FOUND}")

if(CCACHE_FOUND)
    set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif(CCACHE_FOUND)

# CHeck that we may enable code coverage
if(ENABLE_COVERAGE_IN_DEBUG AND CMAKE_COMPILER_IS_GNUCXX)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "[#] Code coverage is enabled")
        set(CODE_COVERAGE_ENABLED ON)
    endif()
endif()


if(CODE_COVERAGE_ENABLED)
    include("cmake/CodeCoverage.cmake")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(bench)
