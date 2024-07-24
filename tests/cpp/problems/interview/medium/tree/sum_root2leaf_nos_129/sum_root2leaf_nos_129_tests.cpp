#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "root_to_leaf.hpp"
#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "iview_file_utils.hpp"

using namespace algo::interview::medium::tree::root2leaf;

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class Root2SumTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
protected:
    BaseLoader loader;
    LoadBst bst_loader;
};


TEST_F(Root2SumTests, Scenario1) {
    Root2Leaf solution;

    int expected{25};


    std::string input("1,2,3");
    TreeNode* root = bst_loader.load_bst(input);
    auto result = solution.sumNumbers(root);
    ASSERT_EQ(expected, result);
}

TEST_F(Root2SumTests, Scenario2) {
    Root2Leaf solution;

    int expected{1026};


    std::string input("4,9,0,5,1");
    TreeNode* root = bst_loader.load_bst(input);
    auto result = solution.sumNumbers(root);
    ASSERT_EQ(expected, result);
}

TEST_F(Root2SumTests, Scenario3) {
    Root2Leaf solution;

    int expected{1};

    std::string input("0,1");
    TreeNode* root = bst_loader.load_bst(input);
    auto result = solution.sumNumbers(root);
    ASSERT_EQ(expected, result);
}

TEST_F(Root2SumTests, RunTestsFromResource)
{
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("binary_tree");
    auto usecase_dir = path / "sum_root2leaf_nos_129";

    Root2Leaf solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        TreeNode* root = tc.getInput();
        auto expected = tc.getExpected();
        auto actual = solution.sumNumbers(root);
        ASSERT_EQ(expected, actual);
    }
}