project(algo.cpp.problems.interview.medium.bt.subsets_78)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/subsets.hpp subsets.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)