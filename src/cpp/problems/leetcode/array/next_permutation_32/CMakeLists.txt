project(algo.cpp.problems.leetcode.array.next_permutation_896)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/next_permutation.hpp next_permutation.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)