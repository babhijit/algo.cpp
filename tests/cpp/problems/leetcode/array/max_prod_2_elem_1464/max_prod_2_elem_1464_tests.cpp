#include "test_case.hpp"

#include "max_product.hpp"
#include "lc_file_utils.hpp"

#include <gtest/gtest.h>

using namespace algo::problems::leetcode::array::max_product_1464;

class MaxProductOf2ElementsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    void run_test(std::vector<int> &nums, int expected) {

        auto exec = [](std::vector<int> &nums, int expected) {
            MaxProduct solution;
            auto result = solution.maxProduct(nums);

            ASSERT_EQ(expected, result);
        };

        ASSERT_NO_THROW(exec(nums, expected));
    }
};


TEST_F(MaxProductOf2ElementsTests, YellowStrips16_4x4) {
    std::vector<int> input({4, 2, 5, 9});
    run_test(input, 32);
}

TEST_F(MaxProductOf2ElementsTests, YellowStrips4_1) {
    std::vector<int> input({1,5,4,5});
    run_test(input, 16);
}

TEST_F(MaxProductOf2ElementsTests, RunTestsFromResources) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "max_prod_2_elem_1464";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [&](auto const &testcase) {
                      TestCase tc(testcase);

                      auto input = tc.getInput();
                      auto expected = tc.getExpected();

                      run_test(input, expected);
                  });
}

