project(algo.cpp.problems.leetcode.array.diff_btwn_1s_0s_2482)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/diff_btwn_1s_0s.hpp  diff_btwn_1s_0s.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)