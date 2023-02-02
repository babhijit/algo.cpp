#include <vector>
#include <utility>

#include <gtest/gtest.h>

#include "remove_nth_node_from_list_end.hpp"

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::list::remove_nth_node_from_list_end;
using namespace algo::cpp::ds::tests::utils;

class RemoveNthNodeFromListEndTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(RemoveNthNodeFromListEndTests, LeetCodeSample1) {
    RemoveNthNodeFromListEnd solution;

    std::vector<int> nums{1, 2, 3, 4, 5};
    auto input = TestCase::load_list(std::move(nums));
    int n = 2;
    auto expected = TestCase::load_list(std::vector({1, 2, 3, 5}));

    auto actual = solution.removeNthNodeFromEnd(input, n);
    ASSERT_EQ(ListNode::to_string(expected), ListNode::to_string(actual));
}


TEST_F(RemoveNthNodeFromListEndTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("list");
    auto usecase_dir = path / "remove_nth_node_from_end_19";

    BaseLoader loader;
    RemoveNthNodeFromListEnd solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto input = tc.getInput();
        auto n = tc.getN();
        auto actual = solution.removeNthNodeFromEnd(input, n);
        auto expected = tc.getExpected();
        ASSERT_EQ(ListNode::to_string(expected), ListNode::to_string(actual));
    }
}