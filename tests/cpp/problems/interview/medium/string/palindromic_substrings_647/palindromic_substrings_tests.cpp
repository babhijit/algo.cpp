#include <gtest/gtest.h>

#include "test_case.hpp"
#include <palindromic_substrings.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::interview::medium::string::palindromic_substring;


class PalindromicSubstringsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::string s, int expected) {
        PalindromicSubstrings solution;
        auto actual = solution.countSubstrings(s);

        ASSERT_EQ(actual, expected);
    }
};


TEST_F(PalindromicSubstringsTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("string");
    auto usecase_dir = path / "palindromic_substrings_647";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getS(), tc.getExpected());
                     });
}