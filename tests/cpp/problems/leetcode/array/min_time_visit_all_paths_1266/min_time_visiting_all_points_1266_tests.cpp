
#include "test_case.hpp"

#include "min_time_visiting_all_points.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

#include <vector>


using namespace algo::problems::leetcode::array::min_time_visiting_all_points;

class MinTimeVisitingAllPointsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void run_test(std::vector<std::vector<int>> points, int expected) {
        MinTimeVisitingAllPoints solution;
        auto result = solution.minTimeToVisitAllPoints(points);
        ASSERT_EQ(expected, result);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();

        run_test(std::move(input), expected);
    }
};


TEST_F(MinTimeVisitingAllPointsTests, LeetCodeSample1) {
    run_test({{1,1}, {3,4}, {-1,0}}, 7);
}

TEST_F(MinTimeVisitingAllPointsTests, LeetCodeSample2) {
    run_test({{3,2}, {-2,2}}, 5);
}

TEST_F(MinTimeVisitingAllPointsTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "min_time_visit_all_points_1266";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      run_test_case(testcase);
                  });
}
