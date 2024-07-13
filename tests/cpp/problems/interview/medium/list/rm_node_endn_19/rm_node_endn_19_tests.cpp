#include <vector>
#include <utility>

#include <gtest/gtest.h>

#include "remove_nth_node_from_end.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::interview::medium::ll::rm_nth_end_node;
using namespace algo::cpp::ds::tests::utils;

class RmNthNodeFromListEndTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    void runTest(ListNode* head, int n, ListNode* expected) {
        RemoveNthNodeFromEnd solution;
        auto actual = solution.removeNthFromEnd(head, n);
        ASSERT_EQ(ListNode::to_string(expected), ListNode::to_string(actual));
    }
};


TEST_F(RmNthNodeFromListEndTests, LeetCodeSample1) {
    std::vector<int> nums{1, 2, 3, 4, 5};
    auto input = TestCase::load_list(std::move(nums));
    int n = 2;
    auto expected = TestCase::load_list(std::vector({1, 2, 3, 5}));

    runTest(input, n, expected);
}

TEST_F(RmNthNodeFromListEndTests, LeetCodeSample2) {
    std::vector<int> nums{1};
    auto input = TestCase::load_list(std::move(nums));
    int n = 1;
    auto expected = TestCase::load_list(std::vector<int>({}));

    runTest(input, n, expected);
}

TEST_F(RmNthNodeFromListEndTests, LeetCodeSample3) {
    std::vector<int> nums{1,2};
    auto input = TestCase::load_list(std::move(nums));
    int n = 1;
    auto expected = TestCase::load_list(std::vector<int>({1}));

    runTest(input, n, expected);
}


TEST_F(RmNthNodeFromListEndTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("list");
    auto usecase_dir = path / "remove_nth_node_from_end_19";

    BaseLoader loader;
    RemoveNthNodeFromEnd solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto n = tc.getN();
        auto expected = tc.getExpected();
        runTest(input, n, expected);
    }
}