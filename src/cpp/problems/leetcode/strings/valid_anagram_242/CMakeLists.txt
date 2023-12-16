project(algo.cpp.problems.leetcode.strings.valid_anagram_242)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/valid_anagram.hpp valid_anagram.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)