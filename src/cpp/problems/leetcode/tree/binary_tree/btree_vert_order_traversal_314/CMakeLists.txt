project(algo.cpp.problems.leetcode.tree.binary_tree.bt_vert_order_traversal_314)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/bt_vert_order_traversal.hpp bt_vert_order_traversal.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)