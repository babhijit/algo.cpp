project(algo.cpp.problems.leetcode.array.buy_2_choc_2706)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/buy_2_choc.hpp  buy_2_choc.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)