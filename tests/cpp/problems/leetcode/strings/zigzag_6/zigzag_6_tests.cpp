#include "test_case.hpp"

#include "zigzag.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::zigzag_6;
using namespace algo::cpp::ds::tests::utils;

class ZigZagTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::string const &s, std::int32_t numRows, std::string const &expected) {
        ZigZag solution;
        auto actual = solution.convert(s, numRows);
        ASSERT_EQ(expected, actual);
    }

    void run_test(std::filesystem::path const &testcasePath) {
        TestCase tc(testcasePath);

        auto s = tc.getS();
        auto numRows = tc.getNumRows();
        auto expected = tc.getExpected();
        run_test(s, numRows, expected);
    }
};


TEST_F(ZigZagTests, LeetCodeSample1) {
    run_test("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
}

TEST_F(ZigZagTests, LeetCodeSample2) {
    run_test("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
}

TEST_F(ZigZagTests, LeetCodeSample3) {
    run_test("AB", 1, "AB");
}


TEST_F(ZigZagTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "zigzag_6";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        run_test(testcase.path());
    }
}