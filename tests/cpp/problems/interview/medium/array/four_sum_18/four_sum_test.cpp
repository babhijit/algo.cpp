
#include "test_case.hpp"

#include "four_sum.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::four_sum;

class FourSumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int target, std::vector<std::vector<int>> expected) {
        FourSum solution;
        auto result = solution.fourSum(nums, target);
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


TEST_F(FourSumTests, LeetCodeSample1) {
    runTest({1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2},
                                      {-2, 0,  0, 2},
                                      {-1, 0,  0, 1}});
}

TEST_F(FourSumTests, LeetCodeSample2) {
    runTest({2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}});
}

TEST_F(FourSumTests, LeetCodeSample3) {
    runTest({-3, -2, -1, 0, 0, 1, 2, 3},
            0,
            {
                    {-3,-2,2,3},
                    {-3,-1,1,3},
                    {-3,0,0,3},
                    {-3,0,1,2},
                    {-2,-1,0,3},
                    {-2,-1,1,2},
                    {-2,0,0,2},
                    {-1,0,0,1}
            });
}

TEST_F(FourSumTests, LeetCodeSample4) {
    runTest({1000000000,1000000000,1000000000,1000000000}, -294967296, {});
}


TEST_F(FourSumTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "four_sum_18";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
