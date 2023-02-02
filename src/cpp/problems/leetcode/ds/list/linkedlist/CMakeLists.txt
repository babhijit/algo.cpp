project(algo.cpp.problems.leetcode.ds.list.linkedlist)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/list_node.hpp list_node.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)