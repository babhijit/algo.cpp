project(algo.cpp.problems.interview.medium.tree.sum_root2leaf_nos_129)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/root_to_leaf.hpp
        root_to_leaf.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)