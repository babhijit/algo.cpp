project(algo.cpp.interview.medium.random_pick_with_weight_528)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/random_pick.hpp random_pick.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)