#include <gtest/gtest.h>

#include <vector>

#include <min_size_subarray_sum.hpp>

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"

#include "test_case.hpp"

#include "min_size_subarray_sum_sliding_window.hpp"

using namespace algo::problems::leetcode::array::min_size_subarray_sum;

class MinSizeSubarraySumSlidingWindowTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    void run_test(std::vector<int> nums, int target, int expected) {
        MinSizeSubarraySum solution(new MinSizeSubarraySum_SlidingWindow());
        auto result = solution.minSubArrayLen(target, nums);
        ASSERT_EQ(expected, result);
    }

};


TEST_F(MinSizeSubarraySumSlidingWindowTests, LeetCodeSample1) {
    run_test({2, 3, 1, 2, 4, 3}, 7, 2);
}

TEST_F(MinSizeSubarraySumSlidingWindowTests, LeetCodeSample2) {
    run_test({1, 4, 4}, 4, 1);
}

TEST_F(MinSizeSubarraySumSlidingWindowTests, LeetCodeSample4) {
    run_test({1,2,3,4,5}, 15, 5);
}

TEST_F(MinSizeSubarraySumSlidingWindowTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "min_size_subarray_sum_209";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto target = tc.getTarget();
        auto expected = tc.getExpected();

        run_test(std::move(input), target, expected);
    }
}
