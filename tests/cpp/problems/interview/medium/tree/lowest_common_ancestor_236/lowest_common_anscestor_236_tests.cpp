#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "lowest_common_ancestor.hpp"

using namespace algo::interview::medium::tree::lowest_common_ancestor;

using namespace algo::cpp::leetcode::ds;

class LowestCommonAncestorTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}


public:
    void runTest(TreeNode *root, TreeNode* p, TreeNode *q, TreeNode *expected) {
        auto exec = [](TreeNode *root, TreeNode *p, TreeNode* q, TreeNode *expected) {
            LowestCommonAncestor solution;
            auto actual = solution.lowestCommonAncestor(root, p, q);

            ASSERT_EQ(expected->val, actual->val);
        };

        ASSERT_NO_THROW(exec(root, p, q, expected));
    }
};


TEST_F(LowestCommonAncestorTests, Scenario1) {
    auto* node3 = new TreeNode(3);
    auto* node5 = new TreeNode(5);
    auto* node1 = new TreeNode(1);
    node3->left = node5;
    node3->right = node1;
    auto* node6 = new TreeNode(6);
    auto* node2 = new TreeNode(6);
    node5->left = node6;
    node5->right = node2;
    auto* node0 = new TreeNode(0);
    auto* node8 = new TreeNode(8);
    node1->left = node0;
    node1->right = node8;
    auto* node7 = new TreeNode(7);
    auto* node4 = new TreeNode(4);
    node2->left = node7;
    node2->right = node4;

    runTest(node3, node5, node1, node3);
}

TEST_F(LowestCommonAncestorTests, Scenario2) {
    auto* node3 = new TreeNode(3);
    auto* node5 = new TreeNode(5);
    auto* node1 = new TreeNode(1);
    node3->left = node5;
    node3->right = node1;
    auto* node6 = new TreeNode(6);
    auto* node2 = new TreeNode(6);
    node5->left = node6;
    node5->right = node2;
    auto* node0 = new TreeNode(0);
    auto* node8 = new TreeNode(8);
    node1->left = node0;
    node1->right = node8;
    auto* node7 = new TreeNode(7);
    auto* node4 = new TreeNode(4);
    node2->left = node7;
    node2->right = node4;

    runTest(node3, node5, node4, node5);
}

TEST_F(LowestCommonAncestorTests, LeetCodeSample3) {
    auto * node1 = new TreeNode(1);
    auto* node2 = new TreeNode(2);
    node1->left = node2;

    runTest(node1, node1, node2, node1);
}
