cmake_minimum_required(VERSION 3.11.2)
project(zcm)

if(POLICY CMP0077)
	# allow overriding options when used as cmake subdirectory
	cmake_policy(SET CMP0077 NEW)
endif()

option(ZCM_ENABLE_TESTS "Build tests" ON)
option(ZCM_ENABLE_COVERAGE_IN_DEBUG "Build code coverage report" ON)
option(ZCM_GENERATE_BENCHMARK "Generate benchmark code" OFF)
option(ZCM_ENABLE_SWIZZLE "Enable GLSL-style swizzling support" ON)


# CHeck that we may enable code coverage
if(ZCM_ENABLE_COVERAGE_IN_DEBUG AND CMAKE_COMPILER_IS_GNUCXX)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "[#] Code coverage is enabled")
        set(ZCM_CODE_COVERAGE_ENABLED ON)
    endif()
endif()

if(ZCM_CODE_COVERAGE_ENABLED)
    include("cmake/CodeCoverage.cmake")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fprofile-arcs -ftest-coverage")
endif()


#--- ZCM library sources ---

add_library(zcm STATIC
    src/angle_and_trigonometry.cpp
    src/common.cpp
    src/color_space.cpp
    src/constants.cpp
    src/component_wise.cpp
    src/exponential.cpp
    src/geometric.cpp
    src/mat2.cpp
    src/mat3.cpp
    src/mat4.cpp
    src/matrix.cpp
    src/matrix_transform.cpp
    src/quat.cpp
    src/quaternion.cpp
    src/type_ptr.cpp
    src/vec2.cpp
    src/vec2_access.cpp
    src/vec3.cpp
    src/vec3_access.cpp
    src/vec4.cpp
    src/vec4_access.cpp
    src/bvec2.cpp
    src/bvec3.cpp
    src/bvec4.cpp
    src/hash.cpp
)

add_library(zcm::zcm ALIAS zcm)
target_include_directories(zcm PUBLIC include)
set_target_properties(zcm
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

#-------------------

if(NOT ZCM_ENABLE_SWIZZLE)
	target_compile_definitions(zcm PUBLIC ZCM_DISABLE_SWIZZLE)
endif()

if(ZCM_ENABLE_TESTS)
    enable_testing()
    add_definitions(-DGLM_ENABLE_EXPERIMENTAL=1 -DGLM_GTX_norm=1)
    add_subdirectory(test)
endif()


if(ZCM_GENERATE_BENCHMARK)
    add_subdirectory(third_party/fmt)
    add_subdirectory(tools)
endif()

export(PACKAGE ${PROJECT_NAME})
