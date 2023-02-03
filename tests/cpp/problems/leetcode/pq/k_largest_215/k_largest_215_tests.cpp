#include <vector>
#include <utility>

#include <gtest/gtest.h>

#include "k_largest.hpp"

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::pq::k_largest;
using namespace algo::cpp::ds::tests::utils;

class KLargestTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(KLargestTests, LeetCodeSample1) {
    KLargest solution;

    std::vector<int> nums{3,2,1,5,6,4};
    int k = 2;
    int expected = 5;

    auto actual = solution.findKthLargest(nums, k);
    ASSERT_EQ(expected, actual);
}


TEST_F(KLargestTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("pq");
    auto usecase_dir = path / "k_largest_215";

    BaseLoader loader;
    KLargest solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto input = tc.getInput();
        auto k = tc.getK();
        auto expected = tc.getExpected();
        auto actual = solution.findKthLargest(input, k);
        ASSERT_EQ(expected, actual);
    }
}