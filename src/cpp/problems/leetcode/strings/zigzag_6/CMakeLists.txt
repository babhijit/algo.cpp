project(algo.cpp.problems.leetcode.strings.zigzag_6)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/zigzag.hpp zigzag.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)