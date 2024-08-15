
#include "test_case.hpp"

#include "subsets.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <set>
#include <vector>


using namespace algo::interview::medium::bt::subsets_ii;

std::vector<std::vector<int>> toSet(Matrix<int>& matrix) {
    std::vector<std::vector<int>> result;

    for (auto& vec: matrix) {
        std::vector<int> row(vec.begin(), vec.end());
        std::sort(row.begin(), row.end());
        result.push_back(row);
    }

    std::sort(result.begin(), result.end());
    std::set<std::vector<int>> uniqueSubsets;
    for (auto& subset: result) {
        uniqueSubsets.insert(subset);
    }
    return {uniqueSubsets.begin(), uniqueSubsets.end()};
}

class SubsetsIITests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, Matrix<int> expected) {
        Subsets solution;
        auto result = solution.subsetsWithDup(nums);
        ASSERT_EQ(toSet(expected), toSet(result));
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), std::move(expected));
    }
};

TEST_F(SubsetsIITests, LeetCodeExample1) {
    runTest({1, 2, 3}, {{}, {1}, {1, 2}, {1, 3}, {1, 2, 3}, {2}, {2, 3}, {3}});
}

TEST_F(SubsetsIITests, LeetCodeExample2) {
    runTest({1, 2, 2}, {{}, {1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}});
}

TEST_F(SubsetsIITests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("bt");
    auto usecase_dir = path / "subsets_ii_90";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
