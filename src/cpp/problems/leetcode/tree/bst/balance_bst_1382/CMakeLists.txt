project(algo.cpp.problems.leetcode.tree.bst.balance_bst_1382)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/balance_bst.hpp balance_bst.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        algo.cpp.problems.leetcode.ds.tree.bst
)

target_include_directories(${PROJECT_NAME} PUBLIC include)