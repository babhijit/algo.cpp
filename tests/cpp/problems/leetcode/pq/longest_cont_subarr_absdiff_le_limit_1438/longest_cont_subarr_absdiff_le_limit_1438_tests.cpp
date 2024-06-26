#include <vector>

#include <gtest/gtest.h>

#include "longest_cont_subarr.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::pq::longest_cont_subarr_absdiff_le_limit;
using namespace algo::cpp::ds::tests::utils;

class LongestSubarrayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<int> nums, int limit, int expected) {
        LongestContinousSubArray solution;

        auto actual = solution.longestSubarrary(nums, limit);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(LongestSubarrayTests, LeetCodeSample1) {
    runTest({8,2,4,7}, 4, 2);
}

TEST_F(LongestSubarrayTests, LeetCodeSample2) {
    runTest({10,1,2,4,7,2}, 5, 4);
}

TEST_F(LongestSubarrayTests, LeetCodeSample3) {
    runTest({4,2,2,2,4,4,2,2}, 0, 3);
}


TEST_F(LongestSubarrayTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("pq");
    auto usecase_dir = path / "longest_cont_subarr_absdiff_le_limit_1438";

    BaseLoader loader;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);

        TestCase tc(boost::json::parse(json_str));
        runTest(tc.getNums(), tc.getLimit(), tc.getExpected());
    }
}