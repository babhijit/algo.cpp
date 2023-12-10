#include "transpose_matrix.hpp"

#include <vector>

#include <gtest/gtest.h>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::transpose_matrix;

class TransportMatrixTests : public ::testing::Test {
protected:
    using IntMatrix = std::vector<std::vector<int>>;

protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(IntMatrix input, const IntMatrix expected) {
        TransportMatrix solution;
        auto actual = solution.transpose(input);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        run_test(tc.getInput(), tc.getExpected());
    }
};

TEST_F(TransportMatrixTests, EmptyMatrix) {
    run_test({}, {});
}

TEST_F(TransportMatrixTests, 1ElementMatrix) {
    run_test({{1}}, {{1}});
}

TEST_F(TransportMatrixTests, LeetCode1) {

    run_test({{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}},
             {{1, 4, 7},
              {2, 5, 8},
              {3, 6, 9}});
}

TEST_F(TransportMatrixTests, LeetCode2) {

    run_test({{1, 2, 3},
              {4, 5, 6}},
             {{1, 4},
              {2, 5},
              {3, 6}});
}

TEST_F(TransportMatrixTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "transpose_matrix_867";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      run_test_case(testcase);
                  });
}