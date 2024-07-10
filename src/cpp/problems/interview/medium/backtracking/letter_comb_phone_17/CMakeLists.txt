project(algo.cpp.problems.interview.medium.backtracking.letter_comb_phone_17)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/letter_combinations.hpp letter_combinations.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)