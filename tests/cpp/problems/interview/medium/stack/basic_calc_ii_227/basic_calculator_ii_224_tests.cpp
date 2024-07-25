#include <gtest/gtest.h>

#include "test_case.hpp"
#include <basic_calc.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::problems::leetcode::interview::stack::basic_calc2;

class BasicCalc2Tests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::string const& s, int expected) {
        BasicCalculator solution;
        auto actual = solution.calculate(s);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(BasicCalc2Tests, TestCase1) {
    runTest("3+2*2", 7);
}

TEST_F(BasicCalc2Tests, TestCase2) {
    runTest(" 3/2", 1);
}

TEST_F(BasicCalc2Tests, TestCase3) {
    runTest("3+5 / 2", 5);
}

TEST_F(BasicCalc2Tests, TestCase4) {
    runTest("2 - 3 + 4*2 -1 + 4/2", 8);
}

TEST_F(BasicCalc2Tests, TestCase5) {
    runTest("0", 0);
}

TEST_F(BasicCalc2Tests, TestCase6) {
    runTest("1 + 1", 2);
}

TEST_F(BasicCalc2Tests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("stack");
    auto usecase_dir = path / "basic_calculator_224";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getS(), tc.getExpected());
                     });
}