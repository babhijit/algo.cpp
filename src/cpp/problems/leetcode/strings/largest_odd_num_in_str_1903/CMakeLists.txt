project(algo.cpp.problems.leetcode.strings.largest_odd_num_in_str_1903)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/largest_odd_num_in_str.hpp largest_odd_num_in_str.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
)

target_include_directories(${PROJECT_NAME} PUBLIC include)