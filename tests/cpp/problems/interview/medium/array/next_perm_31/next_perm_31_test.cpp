
#include "test_case.hpp"

#include "next_perm.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::next_perm_31;

class NextPermutationTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, std::vector<int> expected) {
        NextPermutation solution;
        solution.nextPermutation(nums);
        ASSERT_EQ(expected, nums);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), std::move(expected));
    }
};


TEST_F(NextPermutationTests, LeetCodeSample1) {
    runTest({1, 2, 3}, {1, 3, 2});
}

TEST_F(NextPermutationTests, LeetCodeSample2) {
    runTest({3, 2, 1}, {1, 2, 3});
}

TEST_F(NextPermutationTests, LeetCodeSample3) {
    runTest({1, 1, 5}, {1, 5, 1});
}

TEST_F(NextPermutationTests, LeetCodeSample4) {
    runTest({1,3,2}, {2, 1, 3});
}

TEST_F(NextPermutationTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "next_perm_31";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
