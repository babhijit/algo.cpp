project(algo.cpp.problems.interview.medium.stack.basic_calc2_227)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/basic_calc.hpp basic_calc.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)