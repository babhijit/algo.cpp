
#include "test_case.hpp"

#include "range_search.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::range_search_34;

class RangeSearchTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int target, std::vector<int> const& expected) {
        RangeSearch solution;
        auto result = solution.searchRange(nums, target);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto target = tc.getTarget();
        auto expected = tc.getExpected();

        runTest(std::move(nums), target, std::move(expected));
    }
};


TEST_F(RangeSearchTests, LeetCodeSample1) {
    runTest({5,7,7,8,8,10}, 8, {3, 4});
}

TEST_F(RangeSearchTests, LeetCodeSample2) {
    runTest({5,7,7,8,8,10}, 6, {-1, -1});
}

TEST_F(RangeSearchTests, LeetCodeSample3) {
    runTest({}, 0, {-1, -1});
}


TEST_F(RangeSearchTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "find_first_last_position_in_sorted_array_34";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
