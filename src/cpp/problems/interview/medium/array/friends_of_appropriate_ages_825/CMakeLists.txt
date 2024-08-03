project(algo.interview.medium.array.friends_of_appropriate_ages_825)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/friends.hpp friends.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)