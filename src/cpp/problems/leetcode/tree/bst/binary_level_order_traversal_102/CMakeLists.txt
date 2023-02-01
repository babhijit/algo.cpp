project(algo.cpp.problems.leetcode.tree.bst.binary_level_order_traversal_102)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/level_order_traversal.hpp level_order_traversal.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)