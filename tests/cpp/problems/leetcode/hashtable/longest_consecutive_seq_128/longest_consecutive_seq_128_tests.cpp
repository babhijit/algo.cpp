#include <vector>

#include <gtest/gtest.h>

#include "longest_consecutive_sequence.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::longest_consecutive_seq;

class LongestConsecutiveSequenceTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(LongestConsecutiveSequenceTests, LeetCodeSample1) {
    LongestConsecutiveSequence solution;

    std::vector<int> nums{100,4,200,1,3,2};
    int expected = 4;

    auto actual = solution.longestConsecutive(nums);
    ASSERT_EQ(expected, actual);
}

TEST_F(LongestConsecutiveSequenceTests, LeetCodeSample2) {
    LongestConsecutiveSequence solution;

    std::vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    int expected = 9;

    auto actual = solution.longestConsecutive(nums);
    ASSERT_EQ(expected, actual);
}


TEST_F(LongestConsecutiveSequenceTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("hashtable");
    auto usecase_dir = path / "longest_consecutive_seq_128";

    BaseLoader loader;
    LongestConsecutiveSequence solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto nums = tc.getInput();
        auto actual = solution.longestConsecutive(nums);
        auto expected = tc.getExpected();
        ASSERT_EQ(expected, actual);
    }
}