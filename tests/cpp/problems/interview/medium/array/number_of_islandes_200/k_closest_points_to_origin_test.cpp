
#include "test_case.hpp"

#include "k_closest_points_to_origin.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::k_closest_pt_to_origin;

class KClosestPointsToOriginTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(Matrix points, int k, Matrix expected) {
        KClosestPointsToOrigin solution;
        auto result = solution.kClosest(points, k);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        runTest(tc.getPoints(), tc.getK(), tc.getExpected());
    }
};


TEST_F(KClosestPointsToOriginTests, LeetCodeSample1) {
    runTest({{1,3},{2,-2}}, 1, {{2,-2}});
}

TEST_F(KClosestPointsToOriginTests, LeetCodeSample2) {
    runTest({{3, 3}, {5, -1}, {-2, 4}}, 2, {{3, 3},{-2, 4}});
}

TEST_F(KClosestPointsToOriginTests, LeetCodeSample3) {
    runTest({{6, 10}, {-3, 3}, {-2,5}, {0,2}}, 3, {{0,2},{-3, 3},{-2, 5}});
}

TEST_F(KClosestPointsToOriginTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "k_closest_pts_to_origin_973";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
