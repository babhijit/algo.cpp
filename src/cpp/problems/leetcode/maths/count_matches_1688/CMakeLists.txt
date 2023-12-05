project(algo.cpp.problems.leetcode.maths.count_matches_1688)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/count_matches.hpp count_matches.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)