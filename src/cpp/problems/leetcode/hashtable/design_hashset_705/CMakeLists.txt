project(algo.cpp.problems.leetcode.hashtable.design_hashset_705)


include_directories(include)

add_library(${PROJECT_NAME} STATIC include/my_hashset.hpp my_hashset.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)