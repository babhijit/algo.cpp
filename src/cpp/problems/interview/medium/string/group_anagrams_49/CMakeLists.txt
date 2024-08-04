project(algo.cpp.problems.interview.medium.string.group_anagrams_49)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/grp_anagrams.hpp grp_anagrams.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)