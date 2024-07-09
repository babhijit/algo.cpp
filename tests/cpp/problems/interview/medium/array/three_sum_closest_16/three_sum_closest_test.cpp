
#include "test_case.hpp"

#include "three_sum_closest.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::three_sum_closest;

class ThreeSumClosestTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> points, int target, int expected) {
        ThreeSumCloset solution;
        auto result = solution.threeSumClosest(points, target);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto target = tc.getTarget();
        auto expected = tc.getExpected();

        runTest(std::move(nums), target, expected);
    }
};


TEST_F(ThreeSumClosestTests, LeetCodeSample1) {
    runTest({-1,2,1,-4}, 1, 2);
}

TEST_F(ThreeSumClosestTests, LeetCodeSample2) {
    runTest({0, 0, 0}, 1, 0);
}

TEST_F(ThreeSumClosestTests, LeetCodeSample3) {
    runTest({4,0,5,-5,3,3,0,-4,-5}, -2, -2);
}

TEST_F(ThreeSumClosestTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "three_sum_closest_16";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
