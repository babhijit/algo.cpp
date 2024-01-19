project(algo.cpp.problems.leetcode.maths.climbing_stairs_70)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/climbing_stairs.hpp climbing_stairs.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)