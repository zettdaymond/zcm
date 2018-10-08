hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)


FILE(GLOB_RECURSE zcm_test_SRCs
    "*.h"
    "*.cpp"
    "*.hpp"
)

add_executable(zcm_test ${zcm_test_SRCs})

target_link_libraries(zcm_test zcm::zcm)
target_link_libraries(zcm_test GTest::main) # GTest::gtest will be linked automatically
