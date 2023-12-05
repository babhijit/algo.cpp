#include <gtest/gtest.h>

#include <boost/json.hpp>

#include <monotonic_array.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"

using namespace algo::problems::leetcode::array::monotonic;

class MonotonicArrayTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(MonotonicArrayTests, EqualArrayIsMonotone) {
    MonotonicArray solution;

    std::vector<int> input{1, 1, 1};

    auto result = solution.isMonotonic(input);
    ASSERT_TRUE(result);
}

TEST_F(MonotonicArrayTests, ArrayIsMonotoneAsc) {
    MonotonicArray solution;

    std::vector<int> input{1, 2, 2, 3};

    auto result = solution.isMonotonic(input);
    ASSERT_TRUE(result);
}

TEST_F(MonotonicArrayTests, ArrayIsMonotoneDesc) {
    MonotonicArray solution;

    std::vector<int> input{3, 2, 2, 1};

    auto result = solution.isMonotonic(input);
    ASSERT_TRUE(result);
}

TEST_F(MonotonicArrayTests, ArrayIsNonMonotone) {
    MonotonicArray solution;

    std::vector<int> input{1, 3, 2, 3};

    auto result = solution.isMonotonic(input);
    ASSERT_FALSE(result);
}

TEST_F(MonotonicArrayTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "monotonic_896";

    BaseLoader loader;
    MonotonicArray solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto input = tc.getInput();
        auto actual = solution.isMonotonic(input);
        ASSERT_EQ(tc.getExpected(), actual);
    }
}