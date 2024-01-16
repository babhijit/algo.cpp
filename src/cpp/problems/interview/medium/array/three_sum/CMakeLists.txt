project(algo.cpp.interview.medium.three_sum)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/three_sum.hpp three_sum.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)