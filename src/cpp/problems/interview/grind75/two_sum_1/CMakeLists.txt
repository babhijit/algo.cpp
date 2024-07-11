project(algo.cpp.interview.grind75.two_sum_1)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/two_sum.hpp two_sum.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)