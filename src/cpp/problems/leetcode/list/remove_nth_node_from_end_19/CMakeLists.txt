project(algo.cpp.problems.leetcode.list.remove_nth_node_from_end_19)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/remove_nth_node_from_list_end.hpp remove_nth_node_from_list_end.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist

        )

target_include_directories(${PROJECT_NAME} PUBLIC include)