#include <gtest/gtest.h>

#include "tree_node.hpp"
#include "lowest_common_ancestor.hpp"

using namespace algo::interview::medium::tree::lowest_common_ancestor_bst;

using namespace algo::cpp::leetcode::ds;

class LowestCommonAncestorTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    std::pair<TreeNode*, TreeNode*> setChildren(TreeNode *root, int left, int right) {
        auto leftChild = new TreeNode(left);
        root->left = leftChild;
        auto rightChild = new TreeNode(right);
        root->right = rightChild;

        return {leftChild, rightChild};
    }


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
    auto* node6 = new TreeNode(6);
    auto [node2, node8] = setChildren(node6, 2, 8);
    auto [node0, node4] = setChildren(node2, 0, 4);
    auto [node7, node9] = setChildren(node8, 7, 9);
    auto [node3, node5] = setChildren(node4, 3, 5);

    runTest(node6, node2, node8, node6);
}

TEST_F(LowestCommonAncestorTests, Scenario2) {
    auto* node6 = new TreeNode(6);
    auto [node2, node8] = setChildren(node6, 2, 8);
    auto [node0, node4] = setChildren(node2, 0, 4);
    auto [node7, node9] = setChildren(node8, 7, 9);
    auto [node3, node5] = setChildren(node4, 3, 5);

    runTest(node6, node2, node4, node2);
}

TEST_F(LowestCommonAncestorTests, LeetCodeSample3) {
    auto * node1 = new TreeNode(2);
    auto* node2 = new TreeNode(1);
    node1->left = node2;

    runTest(node1, node1, node2, node1);
}

TEST_F(LowestCommonAncestorTests, Scenario4) {
    auto* node6 = new TreeNode(6);
    auto [node2, node8] = setChildren(node6, 2, 8);
    auto [node0, node4] = setChildren(node2, 0, 4);
    auto [node7, node9] = setChildren(node8, 7, 9);
    auto [node3, node5] = setChildren(node4, 3, 5);

    runTest(node6, node0, node9, node6);
}

