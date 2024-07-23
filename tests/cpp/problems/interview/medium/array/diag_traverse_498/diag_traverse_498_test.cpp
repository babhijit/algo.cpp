
#include "test_case.hpp"

#include "diag_traverse.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::diag_traverse;

class DiagonalTraverseTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<std::vector<int>> nums, std::vector<int> expected) {
        DiagTraverse solution;
        auto result = solution.findDiagonalOrder(nums);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), std::move(expected));
    }
};


TEST_F(DiagonalTraverseTests, LeetCodeSample1) {
    runTest({{1,2,3},{4,5,6},{7,8,9}}, {1,2,4,7,5,3,6,8,9});
}

TEST_F(DiagonalTraverseTests, LeetCodeSample2) {
    runTest({{1, 2}, {3, 4}}, {1, 2, 3, 4});
}

TEST_F(DiagonalTraverseTests, Scenario1) {
    runTest({{1}}, {1});
}

TEST_F(DiagonalTraverseTests, Scenario2) {
    runTest({{1, 2, 3}}, {1, 2, 3});
}

TEST_F(DiagonalTraverseTests, Scenario3) {
    runTest({{1}, {2}, {3}}, {1, 2, 3});
}


TEST_F(DiagonalTraverseTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "diag_traverse_498";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
