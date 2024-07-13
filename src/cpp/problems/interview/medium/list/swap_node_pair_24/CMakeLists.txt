project(algo.cpp.interview.medium.list.swap_node_pair_24)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/swap_node_pair.hpp swap_node_pair.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
)

target_include_directories(${PROJECT_NAME} PUBLIC include)