add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/gtest" "third_party/gtest")
mark_as_advanced(BUILD_GMOCK BUILD_GTEST gmock_build_tests gtest_build_samples gtest_build_tests
                 gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

set_target_properties(gtest PROPERTIES FOLDER third_party)
set_target_properties(gtest_main PROPERTIES FOLDER third_party)
set_target_properties(gmock PROPERTIES FOLDER third_party)
set_target_properties(gmock_main PROPERTIES FOLDER third_party)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    add_test(${TESTNAME} ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(zcm_test
    geometric_test.cpp
    vec2_test.cpp
    vec3_test.cpp
    vec4_test.cpp
    quat_test.cpp
)

target_link_libraries(zcm_test zcm::zcm)


if(CODE_COVERAGE_ENABLED)
    set(COVERAGE_EXCLUDES "/usr/include/\\*;*/Install/*;*gtest*")
    SETUP_TARGET_FOR_COVERAGE(zcm_coverage zcm_test coverage)
    target_link_libraries(zcm_test gcov)
endif()
