project(algo.cpp.problems.leetcode.strings.largest_3_same_num_2264)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/largest_3_same_num.hpp largest_3_same_num.cpp)

target_link_libraries(${PROJECT_NAME}
        algo.cpp.ds
)

target_include_directories(${PROJECT_NAME} PUBLIC include)