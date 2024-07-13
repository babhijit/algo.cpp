#include <gtest/gtest.h>

#include "test_case.hpp"
#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"
#include <gen_parentheses.hpp>

#include <vector>

using namespace algo::problems::leetcode::interview::backtracing::gen_paren;

class GenParenBtTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(int n, std::vector<std::string> const& expected) {
        GenerateParenthesis solution;
        auto actual = solution.generateParentheses(n);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(GenParenBtTests, TestCase1) {
    runTest(3, {"((()))","(()())","(())()","()(())","()()()"});
}

TEST_F(GenParenBtTests, TestCase2) {
    runTest(1, {"()"});
}

TEST_F(GenParenBtTests, TestCase3) {
    runTest(4, {"(((())))",
                "((()()))",
                "((())())",
                "((()))()",
                "(()(()))",
                "(()()())",
                "(()())()",
                "(())(())",
                "(())()()",
                "()((()))",
                "()(()())",
                "()(())()",
                "()()(())",
                "()()()()"});
}

TEST_F(GenParenBtTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("backtracking");
    auto usecase_dir = path / "gen_paren_22";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getN(), tc.getExpected());
                     });
}