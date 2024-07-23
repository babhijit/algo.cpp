
#include "test_case.hpp"

#include "find_peak_element.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::find_peak_element;

class FindPeakElementTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int expected) {
        FindPeakElement solution;
        auto result = solution.findPeakElement(nums);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), expected);
    }
};


TEST_F(FindPeakElementTests, LeetCodeSample1) {
    runTest({1, 2, 3, 4}, 3);
}

TEST_F(FindPeakElementTests, LeetCodeSample2) {
    runTest({1, 2, 3, 1}, 2);
}

TEST_F(FindPeakElementTests, LeetCodeSample3) {
    runTest({1,2,1,3,5,6,4}, 5);
}


TEST_F(FindPeakElementTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "find_peak_element_162";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
