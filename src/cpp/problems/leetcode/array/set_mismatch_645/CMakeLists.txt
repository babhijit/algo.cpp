project(algo.cpp.problems.leetcode.array.set_mismatch_645)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/set_mismatch.hpp set_mismatch.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)