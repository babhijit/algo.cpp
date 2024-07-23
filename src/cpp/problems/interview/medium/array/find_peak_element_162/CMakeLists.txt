project(algo.cpp.interview.medium.find_peak_element_162)

include_directories(include)

add_library(${PROJECT_NAME} STATIC include/find_peak_element.hpp find_peak_element.cpp)

target_link_libraries(${PROJECT_NAME} algo.cpp.ds)

target_include_directories(${PROJECT_NAME} PUBLIC include)