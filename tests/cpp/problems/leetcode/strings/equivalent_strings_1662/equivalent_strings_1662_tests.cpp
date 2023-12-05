#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "equivalent_strings.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::equivalent_strings;
using namespace algo::cpp::ds::tests::utils;

class FindWordsByCharTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::vector<std::string> const &word1, std::vector<std::string> const &word2, bool expected) {
        EquivalentStrings solution;
        auto actual = solution.areStringsEquivalent(word1, word2);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(FindWordsByCharTests, LeetCodeSample1) {
    run_test({"ab", "c"}, {"a", "bc"}, true);
}

TEST_F(FindWordsByCharTests, LeetCodeSample2) {
    run_test({"a", "cb"}, {"ab", "c"}, false);
}

TEST_F(FindWordsByCharTests, LeetCodeSample3) {
    run_test({"abc", "d", "defg"}, {"abcddefg"}, true);
}


TEST_F(FindWordsByCharTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "equivalent_strings_1662";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto word1 = tc.getWord1();
        auto word2 = tc.getWord2();
        auto expected = tc.getExpected();
        run_test(word1, word2, expected);
    }
}