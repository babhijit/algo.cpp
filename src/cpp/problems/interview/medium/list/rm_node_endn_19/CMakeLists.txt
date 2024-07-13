project(algo.cpp.interview.medium.list.rm_node_endn_19)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/remove_nth_node_from_end.hpp remove_nth_node_from_end.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist
)

target_include_directories(${PROJECT_NAME} PUBLIC include)