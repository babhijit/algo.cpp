
#include "test_case.hpp"

#include "contiguous_array.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::array::contiguous_array;

class ContiguousArrayTest : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> nums, int expected) {
        ContiguousArray solution;
        auto result = solution.findMaxLength(nums);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto nums = tc.getNums();
        auto expected = tc.getExpected();

        runTest(std::move(nums), expected);
    }
};


TEST_F(ContiguousArrayTest, LeetCodeSample1) {
    runTest({0, 1}, 2);
}

TEST_F(ContiguousArrayTest, LeetCodeSample2) {
    runTest({0, 1, 0}, 2);
}


TEST_F(ContiguousArrayTest, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "contiguous_array_525";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
