#include "test_case.hpp"

#include "valid_anagram.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::valid_anagram_242;
using namespace algo::cpp::ds::tests::utils;

class ValidAnagramTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::string const &s, std::string const &t, bool expected) {
        ValidAnagram solution;
        auto actual = solution.isAnagram(s, t);
        ASSERT_EQ(expected, actual);
    }

    void run_test(std::filesystem::path const &testcasePath) {
        TestCase tc(testcasePath);

        auto s = tc.getS();
        auto t = tc.getT();
        auto expected = tc.getExpected();
        run_test(s, t, expected);
    }
};


TEST_F(ValidAnagramTests, LeetCodeSample1) {
    run_test("anagram", "nagaram", true);
}

TEST_F(ValidAnagramTests, LeetCodeSample2) {
    run_test("rat", "car", false);
}


TEST_F(ValidAnagramTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "valid_anagram_242";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test(testcase.path());
    }
}