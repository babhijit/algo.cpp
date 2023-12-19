project(algo.cpp.tests.cpp.problems.leetcode.design.design_flood_rating_system_2353)

find_package(Boost REQUIRED COMPONENTS json)
include_directories(${Boost_INCLUDE_DIR})

set(PROJECT_BINARY design_flood_rating_system_2353_tests)

add_executable(${PROJECT_BINARY} design_food_rating_system_2353_tests.cpp)

target_link_libraries(
        ${PROJECT_BINARY}
        GTest::gtest_main
        ${Boost_LIBRARIES}
        Boost::json
        algo.cpp.ds
        algo.cpp.tests.util
        algo.cpp.tests.leetcode.utils
        algo.cpp.design.leetcode.design_flood_rating_system_2353
)

gtest_discover_tests(${PROJECT_BINARY})
