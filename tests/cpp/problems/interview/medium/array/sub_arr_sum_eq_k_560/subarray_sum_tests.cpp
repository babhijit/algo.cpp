
#include "test_case.hpp"

#include "sub_array_sums.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::sub_array_sum;

class SubArraySumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int k, int expected) {
        SubArraySum solution;
        auto result = solution.subarraySum(nums, k);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        runTest(tc.getNums(), tc.getK(), tc.getExpected());
    }
};


TEST_F(SubArraySumTests, LeetCodeSample1) {
    runTest({1,1,1}, 2, 2);
}

TEST_F(SubArraySumTests, LeetCodeSample2) {
    runTest({1,2,3}, 3, 2);
}

TEST_F(SubArraySumTests, Scenario1) {
    runTest({1,2,3,-2, 1,-1,4,3}, 5, 4);
}

TEST_F(SubArraySumTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecaseDir = path / "sub_arr_sum_eq_k_560";

    std::for_each(std::filesystem::directory_iterator(usecaseDir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
