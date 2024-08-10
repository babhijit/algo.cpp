project(algo.cpp.problems.interview.medium.string.palindromic_substrings_647)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/palindromic_substrings.hpp palindromic_substrings.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)