project(algo.cpp.interview.medium.four_sum)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/four_sum.hpp four_sum.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)