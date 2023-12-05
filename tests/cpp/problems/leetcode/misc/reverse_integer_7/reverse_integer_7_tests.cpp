#include <gtest/gtest.h>

#include "reverse_integer.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::reverse_integer;
using namespace algo::cpp::ds::tests::utils;

class ReverseIntegerTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(int input, int expected) {
        ReverseInteger solution;
        auto actual = solution.reverse(input);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(ReverseIntegerTests, LeetCodeSample1) {
    run_test(123, 321);
}

TEST_F(ReverseIntegerTests, LeetCodeSample2) {
    run_test(-123, -321);
}

TEST_F(ReverseIntegerTests, LeetCodeSample3) {
    run_test(120, 21);
}


TEST_F(ReverseIntegerTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("misc");
    auto usecase_dir = path / "reverse_integer_7";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_test(input, expected);
    }
}