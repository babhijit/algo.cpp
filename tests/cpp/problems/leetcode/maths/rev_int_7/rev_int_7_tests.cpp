#include <gtest/gtest.h>

#include "reverse_integer.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::maths::rev_int;
using namespace algo::cpp::ds::tests::utils;

class ReverseIntTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(int input, int expected) {
        ReverseInteger solution;
        auto actual = solution.reverse(input);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(ReverseIntTests, LeetCodeSample1) {
    run_test(123, 321);
}

TEST_F(ReverseIntTests, LeetCodeSample2) {
    run_test(-123, -321);
}

TEST_F(ReverseIntTests, LeetCodeSample3) {
    run_test(120, 21);
}

TEST_F(ReverseIntTests, LeetCodeSampleNegativeOverflow) {
    run_test(-2147483648, 0);
}

TEST_F(ReverseIntTests, LeetCodeSamplePositiveOverflow) {
    run_test(1534236469, 0);
}

TEST_F(ReverseIntTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("maths");
    auto usecase_dir = path / "rev_int_7";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_test(input, expected);
    }
}