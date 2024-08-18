project(algo.cpp.tests.interview.medium.array.min_meeting_rooms_253)

set(PROJECT_BINARY ${PROJECT_NAME})

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_BINARY}
        min_meeting_rooms_253_test.cpp
)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.tests.cpp.problems.interview.utils
        algo.cpp.interview.medium.array.meeting_rooms_253
)

gtest_discover_tests(${PROJECT_BINARY})
