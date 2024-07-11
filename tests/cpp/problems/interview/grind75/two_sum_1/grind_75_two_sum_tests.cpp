
#include "test_case.hpp"

#include "two_sum.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::grind75::two_sum;

class TwoSumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int target, std::vector<int> expected) {
        TwoSum solution;
        auto result = solution.twoSum(nums, target);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto target = tc.getTarget();
        auto expected = tc.getExpected();

        runTest(std::move(nums), target, std::move(expected));
    }
};


TEST_F(TwoSumTests, LeetCodeSample1) {
    runTest({2,7,11,15}, 9, {0,1});
}

TEST_F(TwoSumTests, LeetCodeSample2) {
    runTest({3,2,4}, 6, {1,2});
}

TEST_F(TwoSumTests, LeetCodeSample3) {
    runTest({3,3}, 6, {0,1});
}

TEST_F(TwoSumTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "two_sum_1";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
