project(algo.cpp.problems.leetcode.ds.tree.binary_tree)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/node.hpp node.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)