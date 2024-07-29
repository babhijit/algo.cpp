project(algo.cpp.interview.medium.array.number_of_islands_200)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/number_of_islands.hpp number_of_islands.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)