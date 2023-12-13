#include "test_case.hpp"

#include "spl_pos_in_bin_matrix.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::array::spl_pos_in_bin_matrix_1582;


class SpecialPositionInBinaryMatrixTests : public ::testing::Test {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(Matrix<int> input, int expected) {
        SpecialPositionInBinaryMatrix solution;
        auto actual = solution.numSpecial(input);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        run_test(tc.getInput(), tc.getExpected());
    }
};

TEST_F(SpecialPositionInBinaryMatrixTests, Example1) {
    run_test({
                     {1, 0, 0},
                     {0, 0, 1},
                     {1, 0, 0}
        }, 1);
}

TEST_F(SpecialPositionInBinaryMatrixTests, Example2) {
    run_test({
                     {1, 0, 0},
                     {0, 1, 0},
                     {0, 0, 1}
             }, 3);
}


TEST_F(SpecialPositionInBinaryMatrixTests, LoadTestCase) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "spl_pos_in_bin_matrix_1582";

    for(const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test_case(testcase);
    }
}