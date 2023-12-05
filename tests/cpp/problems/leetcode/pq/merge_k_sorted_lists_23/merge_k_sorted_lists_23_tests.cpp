#include <vector>

#include <gtest/gtest.h>

#include "merge_k_sorted.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::pq::merge_k_sorted;
using namespace algo::cpp::ds::tests::utils;

class MergeKSortedTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::vector<ListNode*> &lists, ListNode* expected) {
        MergeKSorted solution;
        auto actual = solution.mergeKLists(lists);
        ASSERT_EQ(ListNode::to_string(expected), ListNode::to_string(actual));
    }
};


TEST_F(MergeKSortedTests, LeetCodeSample1) {
    std::vector<ListNode* > lists = TestCase::load_lists_from_vector({{1, 4, 5}, {1, 3, 4}, {2, 6}});

    auto expected = TestCase::load_list(std::vector({1,1,2,3,4,4,5,6}));
    run_test(lists, expected);
}

TEST_F(MergeKSortedTests, LeetCodeSample2) {
    ListNode* list = nullptr;

    ListNode* expected = nullptr;
    std::vector<ListNode*> lists{list};
    run_test(lists, expected);
}


TEST_F(MergeKSortedTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("pq");
    auto usecase_dir = path / "merge_k_sorted_23";

    BaseLoader loader;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_test(input, expected);
    }
}