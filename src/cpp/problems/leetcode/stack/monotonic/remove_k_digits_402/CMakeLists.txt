project(algo.cpp.problems.leetcode.stack.remove_k_digits_402)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/remove_k_digits.hpp remove_k_digits.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)