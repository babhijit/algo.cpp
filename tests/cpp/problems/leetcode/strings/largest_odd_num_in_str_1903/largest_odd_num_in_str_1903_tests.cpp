#include "test_case.hpp"

#include "largest_odd_num_in_str.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::largest_odd_num_in_str;
using namespace algo::cpp::ds::tests::utils;

class LargestOddNumberInStringTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::string const &num, std::string const &expected) {
        LargestOddNumberInString solution;
        auto actual = solution.largestOddNumber(num);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(LargestOddNumberInStringTests, LeetCodeSample1) {
    run_test("52", "5");
}

TEST_F(LargestOddNumberInStringTests, LeetCodeSample2) {
    run_test("4206", "");
}

TEST_F(LargestOddNumberInStringTests, LeetCodeSample3) {
    run_test("35427", "35427");
}


TEST_F(LargestOddNumberInStringTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "largest_odd_num_in_str_1903";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        run_test(tc.getNum(), tc.getExpected());
    }
}