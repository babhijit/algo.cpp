#include <gtest/gtest.h>

#include "longest_uniq_substr.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::strings::longest_uniq_substr;
using namespace algo::cpp::ds::tests::utils;

class LongestUniqueSubstringTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::string const& input, int expected) {
        LongestUniqueSubstring solution;
        auto actual = solution.lengthOfLongestSubstring(input);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(LongestUniqueSubstringTests, LeetCodeSample1) {
    run_test("abcabcbb", 3);
}

TEST_F(LongestUniqueSubstringTests, LeetCodeSample2) {
    run_test("dvdf", 3);
}

TEST_F(LongestUniqueSubstringTests, LeetCodeSample3) {
    run_test("pwwkew", 3);
}

TEST_F(LongestUniqueSubstringTests, LeetCodeTestCase1) {
    run_test("abba", 2);
}


TEST_F(LongestUniqueSubstringTests, LeetCodeTestCase2) {
    run_test("abcabcbb", 3);
}


TEST_F(LongestUniqueSubstringTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "longest_uniq_substr_3";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_test(input, expected);
    }
}