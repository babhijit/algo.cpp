project(algo.cpp.interview.medium.array.meeting_rooms_253)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/meeting_rooms.hpp meeting_rooms.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)