FILE(GLOB_RECURSE benchgen_SRCs
    "*.h"
    "*.cpp"
    "*.hpp"
)

add_executable(benchgen ${benchgen_SRCs})
target_link_libraries(benchgen stdc++fs fmt)

set_target_properties(benchgen
        PROPERTIES
                CXX_STANDARD 17
                CXX_STANDARD_REQUIRED ON
                CXX_EXTENSIONS OFF
)
