
#include "test_case.hpp"

#include "meeting_rooms.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::meeting_rooms_ii;

class MergeIntervalsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void run_test(std::vector<std::vector<int>> intervals, int expected) {
        MeetingRooms solution;
        auto result = solution.minMeetingRooms(intervals);
        ASSERT_EQ(expected, result);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto intervals = tc.getIntervals();
        auto expected = tc.getExpected();

        run_test(std::move(intervals), std::move(expected));
    }
};


TEST_F(MergeIntervalsTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "meeting_rooms_253";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      run_test_case(testcase);
                  });
}
