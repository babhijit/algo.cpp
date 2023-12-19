#include <vector>

#include <gtest/gtest.h>

#include "food_rating_system.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::cpp::design::flood_rating_system_2353;

class FoodRatingSystemTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(FoodRatingSystemTests, LeetCodeSample1) {
    FoodRatingSystem solution(
            {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"},
            {"korean", "japanese", "japanese", "greek", "japanese", "korean"},
            {9, 12, 8, 15, 14, 7}
    );

    std::vector<std::string> results;
    results.emplace_back(solution.highestRated("korean"));
    results.emplace_back(solution.highestRated("japanese"));

    solution.changeRating("sushi", 16);
    results.emplace_back(solution.highestRated("japanese"));

    solution.changeRating("ramen", 16);
    results.emplace_back(solution.highestRated("japanese"));

    std::vector<std::string> expected{"kimchi", "ramen", "sushi", "ramen"};

    ASSERT_EQ(expected, results);
}

TEST_F(FoodRatingSystemTests, LeetCodeSample2) {
    FoodRatingSystem solution(
            {"emgqdbo", "jmvfxjohq", "qnvseohnoe", "yhptazyko", "ocqmvmwjq"},
            {"snaxol", "snaxol", "snaxol", "fajbervsj", "fajbervsj"},
            {2, 6, 18, 6, 5}
    );

    std::vector<std::string> results;

    solution.changeRating("qnvseohnoe", 11);
    results.emplace_back(solution.highestRated("fajbervsj"));

    solution.changeRating("emgqdbo", 3);
    solution.changeRating("jmvfxjohq", 9);
    solution.changeRating("emgqdbo", 14);

    results.emplace_back(solution.highestRated("fajbervsj"));
    results.emplace_back(solution.highestRated("snaxol"));

    std::vector<std::string> expected{"yhptazyko", "yhptazyko", "emgqdbo"};

    ASSERT_EQ(expected, results);
}
