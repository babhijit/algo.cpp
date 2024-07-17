project(algo.cpp.interview.grind75.insert_interval_57)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/insert_interval.hpp insert_interval.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)