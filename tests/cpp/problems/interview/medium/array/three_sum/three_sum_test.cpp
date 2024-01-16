
#include "test_case.hpp"

#include "three_sum.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::three_sum;

class ThreeSumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void run_test(std::vector<int> points, std::vector<std::vector<int>> expected) {
        ThreeSum solution;
        auto result = solution.threeSum(points);
        ASSERT_EQ(expected, result);
    }

    static void run_test_case(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();

        run_test(std::move(input), std::move(expected));
    }
};


TEST_F(ThreeSumTests, LeetCodeSample1) {
    run_test({0, 0, 0}, {{0, 0, 0}});
}

TEST_F(ThreeSumTests, LeetCodeSample2) {
    run_test({0, 1, 1}, {{}});
}

TEST_F(ThreeSumTests, LeetCodeSample3) {
    run_test({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2},
                                     {-1, 0,  1}});
}

TEST_F(ThreeSumTests, LeetCodeSample4) {
    run_test({-1, 0, 1}, {{-1, 0, 1}});
}

TEST_F(ThreeSumTests, LeetCodeSample5) {
    run_test({3, 0, -2, -1, 1, 2},
             {{-2, -1, 3},
              {-2, 0,  2},
              {-1, 0,  1}});
}

TEST_F(ThreeSumTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "three_sum";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      run_test_case(testcase);
                  });
}
