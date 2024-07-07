#include <gtest/gtest.h>

#include "test_case.hpp"
#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"
#include <container_with_most_water.hpp>

using namespace algo::problems::leetcode::interview::greedy::container_with_max_water;

class ContainerWithMostWaterTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<int> nums, int expected) {
        ContainerWithMostWater solution;
        auto actual = solution.maxArea(nums);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(ContainerWithMostWaterTests, TestCase1) {
    runTest({1,8,6,2,5,4,8,3,7}, 49);
}

TEST_F(ContainerWithMostWaterTests, TestCase2) {
    runTest({1,1}, 1);
}

TEST_F(ContainerWithMostWaterTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("greedy");
    auto usecase_dir = path / "container_with_most_water_11";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getNums(), tc.getExpected());
                     });
}