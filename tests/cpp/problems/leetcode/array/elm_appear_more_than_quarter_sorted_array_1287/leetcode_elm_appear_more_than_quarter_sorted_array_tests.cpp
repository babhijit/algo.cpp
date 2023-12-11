#include "test_case.hpp"

#include "elm_in_sorted_array.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::array::elm_in_sorted_array;


class ElementInSortedArrayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void run_test(std::vector<int> input, int expected) {
        ElementInSortedArray solution;
        auto actual = solution.findSpecialInteger(input);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);
        run_test(tc.getInput(), tc.getExpected());
    }
};

TEST_F(ElementInSortedArrayTests, Example1) {
    run_test({1, 2, 2, 6, 6, 6, 6, 7, 10}, 6);
}

TEST_F(ElementInSortedArrayTests, Example2) {
    run_test({1, 1, 2, 2, 3, 3, 3, 3, 3}, 3);
}

TEST_F(ElementInSortedArrayTests, Example3) {
    run_test({1, 1}, 1);
}

TEST_F(ElementInSortedArrayTests, LoadTestCase) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "elm_appear_more_than_quarter_sorted_array_1287";

    for(const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test_case(testcase);
    }
}