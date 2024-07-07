project(algo.cpp.problems.leetcode.strings.str_to_int_8)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/str_to_int.hpp str_to_int.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)