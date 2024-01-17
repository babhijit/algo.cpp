project(algo.cpp.problems.leetcode.hashtable.uniq_occ_1207)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/uniq_occ.hpp uniq_occ.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)