#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "find_index_of_str.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::find_index_of_str_28;
using namespace algo::cpp::ds::tests::utils;

class FindIndexOfStringTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(std::string const &haystack, std::string const &needle, int expected) {
        FindIndexOfString solution;
        auto actual = solution.strStr(haystack, needle);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(FindIndexOfStringTests, LeetCodeSample1) {
    run_test("sadbutsad", "sad", 0);
}

TEST_F(FindIndexOfStringTests, LeetCodeSample2) {
    run_test("leetcode", "leeto", -1);
}

TEST_F(FindIndexOfStringTests, TestCase3) {
    run_test("BCBAABACAABABACAA", "ABABAC", 9);
}


TEST_F(FindIndexOfStringTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "find_index_str_28";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto haystack = tc.getHaystack();
        auto needle = tc.getNeedle();
        auto expected = tc.getExpected();
        run_test(haystack, needle, expected);
    }
}