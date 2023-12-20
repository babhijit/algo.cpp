#include "test_case.hpp"

#include "buy_2_choc.hpp"

#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::array::buy_2_choc_2706;


class Buy2ChocolatesTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(std::vector<int> prices, int money, int expected) {
        Buy2Chocolates solution;
        auto actual = solution.buyChoco(prices, money);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        run_test(tc.getPrices(), tc.getMoney(), tc.getExpected());
    }
};

TEST_F(Buy2ChocolatesTests, Example1) {
    run_test({ 1, 2, 2 },
             3,
             0);
}

TEST_F(Buy2ChocolatesTests, Example2) {
    run_test({ 3, 2, 3 },
             3,
             3);
}


TEST_F(Buy2ChocolatesTests, LoadTestCase) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "buy_2_choc_2706";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test_case(testcase);
    }
}