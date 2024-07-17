
#include "test_case.hpp"

#include "max_subarray.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::grind75::max_subarray;

class MaxSubArrayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int expected) {
        MaxSubArray solution;
        auto result = solution.maxSubArray(nums);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), expected);
    }
};


TEST_F(MaxSubArrayTests, LeetCodeSample1) {
    runTest({-2,1,-3,4,-1,2,1,-5,4}, 6);
}

TEST_F(MaxSubArrayTests, LeetCodeSample2) {
    runTest({1}, 1);
}

TEST_F(MaxSubArrayTests, LeetCodeSample3) {
    runTest({5,4,-1,7,8}, 23);
}

TEST_F(MaxSubArrayTests, LeetCodeSample4) {
    runTest({-2, -1}, -1);
}

TEST_F(MaxSubArrayTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "max_sub_array_53";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
