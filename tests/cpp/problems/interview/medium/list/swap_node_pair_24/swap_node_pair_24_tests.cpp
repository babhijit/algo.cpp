#include <vector>
#include <utility>

#include <gtest/gtest.h>

#include "swap_node_pair.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::interview::medium::ll::swap_node_pairs;
using namespace algo::cpp::ds::tests::utils;

class SwapNodePairTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    void runTest(ListNode* head, ListNode* expected) {
        SwapNodePairs solution;
        auto actual = solution.swapPairs(head);
        ASSERT_EQ(ListNode::to_string(expected), ListNode::to_string(actual));
    }
};


TEST_F(SwapNodePairTests, LeetCodeSample1) {
    std::vector<int> nums{1, 2, 3, 4};
    auto input = TestCase::load_list(std::move(nums));
    auto expected = TestCase::load_list(std::vector({2, 1, 4, 3}));

    runTest(input, expected);
}

TEST_F(SwapNodePairTests, LeetCodeSample2) {
    std::vector<int> nums{};
    auto input = TestCase::load_list(std::move(nums));
    auto expected = TestCase::load_list(std::vector<int>({}));

    runTest(input, expected);
}

TEST_F(SwapNodePairTests, LeetCodeSample3) {
    std::vector<int> nums{1};
    auto input = TestCase::load_list(std::move(nums));
    auto expected = TestCase::load_list(std::vector<int>({1}));

    runTest(input, expected);
}

TEST_F(SwapNodePairTests, LeetCodeSample4) {
    std::vector<int> nums{1, 2, 3, 4, 5};
    auto input = TestCase::load_list(std::move(nums));
    auto expected = TestCase::load_list(std::vector<int>({2, 1, 4, 3, 5}));

    runTest(input, expected);
}


TEST_F(SwapNodePairTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("list");
    auto usecase_dir = path / "swap_node_pair_24";

    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);
        runTest(tc.getInput(), tc.getExpected());
    }
}