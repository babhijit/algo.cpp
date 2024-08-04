#include <gtest/gtest.h>

#include "test_case.hpp"
#include <count_and_say.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::interview::medium::string::count_n_say;

class CountNSayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(int n, std::string const& expected) {
        CountAndSay solution;
        auto actual = solution.countAndSay(n);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(CountNSayTests, TestCase1) {
    runTest(1, "1");
}

TEST_F(CountNSayTests, TestCase2) {
    runTest(2, "11");
}

TEST_F(CountNSayTests, TestCase3) {
    runTest(3, "21");
}

TEST_F(CountNSayTests, TestCase4) {
    runTest(4, "1211");
}

TEST_F(CountNSayTests, TestCase5) {
    runTest(5, "111221");
}

TEST_F(CountNSayTests, TestCase6) {
    runTest(6, "312211");
}

TEST_F(CountNSayTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("string");
    auto usecase_dir = path / "count_n_say_38";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getN(), tc.getExpected());
                     });
}