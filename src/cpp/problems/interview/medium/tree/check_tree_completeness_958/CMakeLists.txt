project(algo.cpp.problems.interview.medium.tree.check_tree_completeness_958)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/complete_btree.hpp
        complete_btree.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)