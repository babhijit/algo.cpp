project(algo.cpp.problems.leetcode.array.min_domino_rotations_1007)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/min_domino_rotations_for_equal_row.hpp
        min_domino_rotations_for_equal_row.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)