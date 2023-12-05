#include <vector>

#include <gtest/gtest.h>

#include <next_permutation.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::next_permutation;

class NextPermutationTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(NextPermutationTests, FirstPermutation) {
    NextPermutation solution;

    std::vector<int> nums{1, 2, 3};
    std::vector<int> expected{1, 3, 2};

    solution.nextPermutation(nums);
    ASSERT_EQ(expected, nums);
}

TEST_F(NextPermutationTests, NextPermutainIsReverse) {
    NextPermutation solution;

    std::vector<int> nums{3, 2, 1};
    std::vector<int> expected{1, 2, 3};

    solution.nextPermutation(nums);
    ASSERT_EQ(expected, nums);
}

TEST_F(NextPermutationTests, NextPermutainFor547532) {
    NextPermutation solution;

    std::vector<int> nums{5,4,7,5,3,2};
    std::vector<int> expected{5,5,2,3,4,7};

    solution.nextPermutation(nums);
    ASSERT_EQ(expected, nums);
}

TEST_F(NextPermutationTests, NextPermutainFor15432) {
    NextPermutation solution;

    std::vector<int> nums{1, 5, 4, 3, 2};
    std::vector<int> expected{2, 1, 3, 4, 5};

    solution.nextPermutation(nums);
    ASSERT_EQ(expected, nums);
}

TEST_F(NextPermutationTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "next_permutation_31";

    BaseLoader loader;
    NextPermutation solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto nums = tc.getInput();
        solution.nextPermutation(nums);
        auto expected = tc.getExpected();
        ASSERT_EQ(expected, nums);
    }
}