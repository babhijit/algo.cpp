#include <gtest/gtest.h>

#include "test_case.hpp"
#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"
#include <jump_game.hpp>

using namespace algo::problems::leetcode::interview::backtracing::jump_game;

class JumpGameBtTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<int> nums, bool expected) {
        JumpGame solution;
        auto actual = solution.canJump(nums);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(JumpGameBtTests, TestCase1) {
    runTest({2, 3, 1, 1, 4}, true);
}

TEST_F(JumpGameBtTests, TestCase2) {
    runTest({3, 2, 1, 0, 4}, false);
}

TEST_F(JumpGameBtTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("backtracking");
    auto usecase_dir = path / "jump_game_55";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getNums(), tc.getExpected());
                     });
}