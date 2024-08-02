project(algo.cpp.problems.interview.medium.tree.bst_to_sorted_doublylinkedlist_426)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/bst2dll.hpp
        bst2dll.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)