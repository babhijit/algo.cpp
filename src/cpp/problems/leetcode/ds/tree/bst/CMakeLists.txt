project(algo.cpp.problems.leetcode.ds.tree.bst)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/tree_node.hpp tree_node.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)