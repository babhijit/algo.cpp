project(algo.cpp.problems.leetcode.tree.bst.largest_bst_subtree_333)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/largest_bst_subtree.hpp largest_bst_subtree.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)