#include <vector>

#include <gtest/gtest.h>

#include <search_in_rotated_array.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::search_in_rotated_array;

class SearchInRotatedTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(SearchInRotatedTests, PositiveSampleCase) {
    SearchInRotatedArray solution;

    std::vector<int> nums{2,5,6,0,0,1,2};
    int target = 0;
    bool expected = true;

    auto actual = solution.search(nums, target);
    ASSERT_EQ(expected, actual);
}

TEST_F(SearchInRotatedTests, NegativeSampleCase) {
    SearchInRotatedArray solution;

    std::vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    int target = 3;
    bool expected = false;

    auto actual = solution.search(nums, target);
    ASSERT_EQ(expected, actual);
}

TEST_F(SearchInRotatedTests, Array_1_0_1_1_1) {
    SearchInRotatedArray solution;

    std::vector<int> nums{1,0,1,1,1};
    int target = 0;
    bool expected = true;

    auto actual = solution.search(nums, target);
    ASSERT_EQ(expected, actual);
}

TEST_F(SearchInRotatedTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "search_in_rotated_array_81";

    BaseLoader loader;
    SearchInRotatedArray solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto nums = tc.getInput();
        auto target = tc.getTarget();
        auto actual = solution.search(nums, target);
        auto expected = tc.getExpected();
        ASSERT_EQ(expected, actual);
    }
}