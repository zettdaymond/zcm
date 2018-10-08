FILE(GLOB_RECURSE zcm_SRCs
    "*.h"
    "*.cpp"
    "*.hpp"
)

add_library(zcmlib ${zcm_SRCs})

add_library(zcm::zcm ALIAS zcmlib)

target_include_directories(zcmlib
    PUBLIC
        $<INSTALL_INTERFACE:zcm>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
)

set_target_properties(zcmlib
        PROPERTIES
                CXX_STANDARD 17
                CXX_STANDARD_REQUIRED ON
                CXX_EXTENSIONS OFF
)
