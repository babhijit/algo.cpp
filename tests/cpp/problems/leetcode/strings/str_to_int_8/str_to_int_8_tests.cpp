#include "test_case.hpp"

#include "str_to_int.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::to_integer;
using namespace algo::cpp::ds::tests::utils;

class StrToIntTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void runTests(std::string const &s, std::int32_t expected) {
        StrToInt solution;
        auto actual = solution.myAtoi(s);
        ASSERT_EQ(expected, actual);
    }

    void runTests(std::filesystem::path const &testcasePath) {
        TestCase tc(testcasePath);

        auto s = tc.getS();
        auto expected = tc.getExpected();
        runTests(s, expected);
    }
};


TEST_F(StrToIntTests, LeetCodeSample1) {
    runTests("42", 42);
}

TEST_F(StrToIntTests, LeetCodeSample2) {
    runTests("-042", -42);
}

TEST_F(StrToIntTests, LeetCodeSample3) {
    runTests("1337c0d3", 1337);
}

TEST_F(StrToIntTests, LeetCodeSample4) {
    runTests("x1337c0d3", 0);
}

TEST_F(StrToIntTests, LeetCodeSample5) {
    runTests("042", 42);
}

TEST_F(StrToIntTests, LeetCodeSample6) {
    runTests("-91283472332", -2147483648);
}

TEST_F(StrToIntTests, LeetCodeSample7) {
    runTests("91283472332", 2147483647);
}

TEST_F(StrToIntTests, LeetCodeSample8) {
    runTests("-2147483647", -2147483647);
}

TEST_F(StrToIntTests, LeetCodeSample9) {
    runTests("2147483648", 2147483647);
}

TEST_F(StrToIntTests, LeetCodeSample10) {
    runTests("-2147483648", -2147483648);
}


TEST_F(StrToIntTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "str_to_int_8";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        runTests(testcase.path());
    }
}