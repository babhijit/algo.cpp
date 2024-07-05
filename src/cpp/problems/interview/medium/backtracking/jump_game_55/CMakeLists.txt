project(algo.cpp.problems.interview.medium.backtracking.jump_game_55)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/jump_game.hpp jump_game.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)