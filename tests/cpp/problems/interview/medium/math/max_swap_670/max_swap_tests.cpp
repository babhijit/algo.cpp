#include <gtest/gtest.h>

#include "test_case.hpp"
#include <max_swap.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::interview::medium::math::max_swap;

class MaxSwapTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(int num, int expected) {
        MaxSwap solution;
        auto actual = solution.maximumSwap(num);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(MaxSwapTests, TestCase1) {
    runTest(2736, 7236);
}

TEST_F(MaxSwapTests, TestCase2) {
    runTest(9973, 9973);
}

TEST_F(MaxSwapTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("math");
    auto usecase_dir = path / "max_swap_670";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getNum(), tc.getExpected());
                     });
}