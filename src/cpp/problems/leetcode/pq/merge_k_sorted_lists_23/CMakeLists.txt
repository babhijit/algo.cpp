project(algo.cpp.problems.leetcode.pq.merge_k_sorted_23)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/merge_k_sorted.hpp merge_k_sorted.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.list.linkedlist

        )

target_include_directories(${PROJECT_NAME} PUBLIC include)