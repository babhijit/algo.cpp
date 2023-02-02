project(algo.cpp.problems.leetcode.array.longest_consecutive_seq_128)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/longest_consecutive_sequence.hpp longest_consecutive_sequence.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)