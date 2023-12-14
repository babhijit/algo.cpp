#include "test_case.hpp"

#include "diff_btwn_1s_0s.hpp"

#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::array::diff_btwn_1s_0s_2482;


class DiffBetween1sAnd0sTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(IntMatrix input, IntMatrix expected) {
        DiffBetween1sAnd0s solution;
        auto actual = solution.onesMinusZeros(input);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        run_test(tc.getInput(), tc.getExpected());
    }
};

TEST_F(DiffBetween1sAnd0sTests, Example1) {
    run_test({
                     {0, 1, 1},
                     {1, 0, 1},
                     {0, 0, 1}
             },
             {
                     {0,  0,  4},
                     {0,  0,  4},
                     {-2, -2, 2}
             });
}

TEST_F(DiffBetween1sAnd0sTests, Example2) {
    run_test({
                     {1, 1, 1},
                     {1, 1, 1}
             },
             {
                     {5, 5, 5},
                     {5, 5, 5}
             });
}


TEST_F(DiffBetween1sAnd0sTests, LoadTestCase) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "diff_btwn_1s_0s_2482";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test_case(testcase);
    }
}