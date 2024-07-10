#include <gtest/gtest.h>

#include "test_case.hpp"
#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"
#include <letter_combinations.hpp>

using namespace algo::problems::leetcode::interview::backtracing::letter_combinations;

class LetterCombinationTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::string const& digit, std::vector<std::string> expected) {
        LetterCombinations solution;
        auto actual = solution.letterCombinations(digit);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(LetterCombinationTests, TestCase1) {
    runTest("23", {"ad","ae","af","bd","be","bf","cd","ce","cf"});
}

TEST_F(LetterCombinationTests, TestCase2) {
    runTest("", {});
}

TEST_F(LetterCombinationTests, TestCase3) {
    runTest("2", {"a","b","c"});
}

TEST_F(LetterCombinationTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("backtracking");
    auto usecase_dir = path / "letter_comb_phone_17";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getDigits(), tc.getExpected());
                     });
}