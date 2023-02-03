project(algo.cpp.problems.leetcode.tree.bst.right_side_view_199)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/bst_right_side_view.hpp bst_right_side_view.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)