project(algo.cpp.problems.interview.medium.math.pow_50)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/pow.hpp pow.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)