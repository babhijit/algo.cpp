project(algo.cpp.problems.leetcode.array.game_of_life_289)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/game_of_life.hpp game_of_life.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)