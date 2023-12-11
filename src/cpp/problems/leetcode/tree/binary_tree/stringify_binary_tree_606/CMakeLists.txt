project(algo.cpp.problems.leetcode.tree.binary_tree.stringify_binary_tree_606)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/stringify_binary_tree.hpp stringify_binary_tree.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)