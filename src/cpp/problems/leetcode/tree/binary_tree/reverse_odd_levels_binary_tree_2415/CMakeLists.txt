project(algo.cpp.problems.leetcode.tree.binary_tree.reverse_odd_levels_2415)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/bt_reverse_odd_level.hpp
        bt_reverse_odd_level.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)