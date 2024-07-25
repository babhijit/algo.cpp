#include <gtest/gtest.h>

#include "test_case.hpp"
#include <pow.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::problems::leetcode::interview::math::pow;

class PowTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(double x, int n, double expected) {
        PoW solution;
        auto actual = solution.myPow(x, n);
        ASSERT_DOUBLE_EQ(actual, expected);
    }
};


TEST_F(PowTests, TestCase1) {
    runTest(2.00, 10, 1024.0);
}

TEST_F(PowTests, TestCase2) {
    runTest(2.1, 3, 9.261);
}

TEST_F(PowTests, TestCase3) {
    runTest(2, -2, 0.25);
}


TEST_F(PowTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("math");
    auto usecase_dir = path / "pow_50";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getX(), tc.getN(), tc.getExpected());
                     });
}