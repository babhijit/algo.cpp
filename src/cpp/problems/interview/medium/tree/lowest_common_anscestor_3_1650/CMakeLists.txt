project(algo.cpp.problems.interview.medium.tree.lowest_common_anscestor_3_1650)

include_directories(include)

add_library(${PROJECT_NAME} STATIC
        include/lowest_common_ancestor.hpp
        lowest_common_ancestor.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.binary_tree
)

target_include_directories(${PROJECT_NAME} PUBLIC include)