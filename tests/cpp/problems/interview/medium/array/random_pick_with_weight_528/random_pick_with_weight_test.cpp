#include <gtest/gtest.h>

#include "random_pick.hpp"

using namespace algo::interview::medium::array::random_pick_with_weight;

class RandomPickWithWeightTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(RandomPickWithWeightTests, LeetCodeSample1) {
    auto input = std::vector < int > {1};
    RandomPick solution(input);
    int result = solution.pickIndex();
    ASSERT_TRUE(result == 0);
}

TEST_F(RandomPickWithWeightTests, LeetCodeSample2) {
    auto input = std::vector < int > {1, 3};
    RandomPick solution(input);
    for (int attempts = 0; attempts < 5; ++attempts) {
        int result = solution.pickIndex();
        ASSERT_TRUE(result == 0 || result == 1);
    }
}
