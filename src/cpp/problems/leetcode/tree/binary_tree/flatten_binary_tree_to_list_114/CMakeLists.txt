project(algo.cpp.problems.leetcode.tree.binary_tree.flatten_binary_tree_to_list_114)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/flatten_binary_tree_to_list.hpp
        flatten_binary_tree_to_list.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)