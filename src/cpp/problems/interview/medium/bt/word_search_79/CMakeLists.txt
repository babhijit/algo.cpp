project(algo.cpp.problems.interview.medium.bt.word_search_79)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/word_search.hpp word_search.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)