#include "test_case.hpp"

#include "count_matches.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::maths::count_matches;

class CountMatchesTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    static void runTestCase(int n, int expected) {
        CountMatches solution;
        auto actual = solution.numberOfMatches(n);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(CountMatchesTests, LeetCodeSample02) {
    runTestCase(14, 13);
}

TEST_F(CountMatchesTests, LeetCodeSample01) {
    runTestCase(7, 6);
}

TEST_F(CountMatchesTests, RunFromResources) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("maths");
    auto usecase_dir = path / "count_matches_1688";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      TestCase tc(testcase);

                      auto input = tc.getInput();
                      auto expected = tc.getExpected();
                      runTestCase(input, expected);
                  });
}