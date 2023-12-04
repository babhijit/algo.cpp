#include <gtest/gtest.h>

#include "largest_3_same_num.hpp"

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::strings::largest_3_same_num;
using namespace algo::cpp::ds::tests::utils;

class Largest3NumberInStringTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void run_test(std::string const &input, std::string const &expected) {
        Largest3NumberInString solution;
        auto actual = solution.largestGoodInteger(input);
        ASSERT_EQ(expected, actual);
    }

    static void run_test_case(std::filesystem::path const &testcase) {
        TestCase tc(testcase);
        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_test(input, expected);
    }
};


TEST_F(Largest3NumberInStringTests, LeetCodeSample1) {
    run_test("6777133339", "777");
}

TEST_F(Largest3NumberInStringTests, LeetCodeSample2) {
    run_test("2300019", "000");
}

TEST_F(Largest3NumberInStringTests, LeetCodeSample3) {
    run_test("42352338", "");
}


TEST_F(Largest3NumberInStringTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "largest_3_same_num_2264";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  run_test_case);
}