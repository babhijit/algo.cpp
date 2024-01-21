project(algo.cpp.problems.interview.medium.dp.house_robber_198)

include_directories(include detail)

add_library(${PROJECT_NAME} STATIC include/dp_house_robber.hpp detail/max_house_robbery.hpp dp_house_robber.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)