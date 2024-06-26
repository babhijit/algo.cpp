project(algo.cpp.problems.leetcode.set.longest_cont_subarr_absdiff_le_limit_1438)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/longest_cont_subarr.hpp longest_cont_subarr.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)