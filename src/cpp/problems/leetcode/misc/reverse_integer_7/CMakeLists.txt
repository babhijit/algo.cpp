project(algo.cpp.problems.leetcode.reverse_integer_7)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/reverse_integer.hpp reverse_integer.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
        )

target_include_directories(${PROJECT_NAME} PUBLIC include)