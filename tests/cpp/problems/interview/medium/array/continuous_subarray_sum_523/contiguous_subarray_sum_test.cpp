
#include "test_case.hpp"

#include "subarray_sum.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::continuous_subarray_sum;

class ContSubarraySumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int k, bool expected) {
        SubarraySum solution;
        auto result = solution.checkSubarraySum(nums, k);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto k = tc.getK();
        auto expected = tc.getExpected();

        runTest(std::move(nums), k, expected);
    }
};


TEST_F(ContSubarraySumTests, LeetCodeSample1) {
    runTest({23,2,4,6,7}, 6, true);
}

TEST_F(ContSubarraySumTests, LeetCodeSample2) {
    runTest({23,2,6,4,7}, 6, true);
}

TEST_F(ContSubarraySumTests, LeetCodeSample3) {
    runTest({23,2,6,4,7}, 13, false);
}


TEST_F(ContSubarraySumTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "continuous_subarray_sum_523";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
