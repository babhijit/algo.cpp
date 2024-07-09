project(algo.cpp.interview.medium.three_sum_closet_16)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/three_sum_closest.hpp three_sum_closest.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)