project(algo.cpp.problems.leetcode.array.house_robber_198)

include_directories(include detail)

add_library(${PROJECT_NAME} STATIC include/house_robber.hpp detail/max_house_robbery.hpp house_robber.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)