
#include "test_case.hpp"

#include "max_consecutive_ones.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::max_consecutive_ones;

class MaxConsecutiveOnesTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int k, int expected) {
        MaxConsecutiveOnes solution;
        auto result = solution.longestOnes(nums, k);
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

TEST_F(MaxConsecutiveOnesTests, LeetCodeSample1) {
    runTest({1,1,1,0,0,0,1,1,1,1,0}, 2, 6);
}

TEST_F(MaxConsecutiveOnesTests, LeetCodeSample2) {
    runTest({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10);
}

TEST_F(MaxConsecutiveOnesTests, LeetCodeSample3) {
    runTest({0,0,1,1,1,0,0}, 0, 3);
}


TEST_F(MaxConsecutiveOnesTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "max_consecutive_ones_1004";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
