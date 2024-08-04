project(algo.cpp.problems.interview.medium.string.count_n_say_38)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/count_and_say.hpp count_and_say.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)