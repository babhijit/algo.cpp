project(algo.cpp.problems.leetcode.tree.bst.validate_bst_98)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/validate_bst.hpp validate_bst.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)