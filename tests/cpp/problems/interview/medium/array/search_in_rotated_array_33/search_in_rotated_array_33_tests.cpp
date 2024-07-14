
#include "test_case.hpp"

#include "search_in_rotated_array.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::search_in_rotated_array_33;

class SearchInRotatedArrayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int target, int expected) {
        SearchInRotatedArray solution;
        auto actual = solution.search(nums, target);
        ASSERT_EQ(expected, actual);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto target = tc.getTarget();
        auto expected = tc.getExpected();

        runTest(std::move(nums), target, expected);
    }
};


TEST_F(SearchInRotatedArrayTests, LeetCodeSample1) {
    runTest({4,5,6,7,0,1,2}, 0, 4);
}

TEST_F(SearchInRotatedArrayTests, LeetCodeSample2) {
    runTest({4,5,6,7,0,1,2}, 3, -1);
}

TEST_F(SearchInRotatedArrayTests, LeetCodeSample3) {
    runTest({1}, 0, -1);
}

TEST_F(SearchInRotatedArrayTests, LeetCodeSample4) {
    runTest({3, 1}, 3, 0);
}

TEST_F(SearchInRotatedArrayTests, LeetCodeSample5) {
    runTest({1, 3}, 3, 1);
}

TEST_F(SearchInRotatedArrayTests, LeetCodeSample6) {
    runTest({5, 1, 3}, 3, 2);
}


TEST_F(SearchInRotatedArrayTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "search_in_rotated_array_33";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
