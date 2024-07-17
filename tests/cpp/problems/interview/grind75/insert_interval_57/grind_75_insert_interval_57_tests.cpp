
#include "test_case.hpp"

#include "insert_interval.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::grind75::insert_interval;
using namespace algo::cpp::ds::tests::utils;

class InsertIntervalTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(IntMatrix intervals, std::vector<int> newInterval, IntMatrix expected) {
        InsertInterval solution;
        auto result = solution.insert(intervals, newInterval);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto intervals = tc.getIntervals();
        auto newIntervals = tc.getNewIntervals();
        auto expected = tc.getExpected();

        runTest(std::move(intervals),
                std::move(newIntervals),
                std::move(expected));
    }
};


TEST_F(InsertIntervalTests, LeetCodeSample1) {
    runTest({{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}});
}

TEST_F(InsertIntervalTests, LeetCodeSample2) {
    runTest({{1,2}, {3,5}, {6,7}, {8,10}, {12,16}},
            {4, 8},
            {{1, 2}, {3, 10}, {12, 16}});
}

TEST_F(InsertIntervalTests, LeetCodeSample3) {
    runTest({{1,2}, {6,7}},
            {4, 5},
            {{1, 2}, {4, 5}, {6, 7}});
}

TEST_F(InsertIntervalTests, LeetCodeSample4) {
    runTest({{1,2}, {6,7}},
            {9, 10},
            {{1, 2}, {6, 7}, {9, 10}});
}

TEST_F(InsertIntervalTests, LeetCodeSample5) {
    runTest({{1,5}},
            {0, 3},
            {{0, 5}});
}

TEST_F(InsertIntervalTests, LeetCodeSample6) {
    runTest({{1,5}},
            {0, 0},
            {{0, 0}, {1, 5}});
}

TEST_F(InsertIntervalTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "insert_interval_57";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
