project(algo.cpp.interview.medium.array.max_consecutive_ones_1004)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/max_consecutive_ones.hpp max_consecutive_ones.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)