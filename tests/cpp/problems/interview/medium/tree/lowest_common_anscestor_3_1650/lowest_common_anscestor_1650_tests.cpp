#include <gtest/gtest.h>

#include <lowest_common_ancestor.hpp>

#include <node.hpp>

using namespace algo::interview::medium::tree::lowest_common_ancestor_3;


class LowestCommonAncestorTests : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {}

    void runTest(Node* p, Node* q, Node* expected) {
        LowestCommonAncestor solution;
        ASSERT_EQ(expected->val, solution.lowestCommonAncestor(p, q)->val);
    }
};

TEST_F(LowestCommonAncestorTests, LeetCodeSample1) {
    Node* node3 = new Node(3);
    Node* node5 = new Node(5, nullptr, nullptr, node3);
    Node* node1 = new Node(1, nullptr, nullptr, node3);
    Node* node6 = new Node(6, nullptr, nullptr, node5);
    Node* node2 = new Node(6, nullptr, nullptr, node5);
    node5->left = node6;
    node5->right = node2;
    Node* node0 = new Node(0, nullptr, nullptr, node1);
    Node* node8 = new Node(8, nullptr, nullptr, node1);
    node1->left = node0;
    node1->right = node8;
    Node* node7 = new Node(7, nullptr, nullptr, node2);
    Node* node4 = new Node(4, nullptr, nullptr, node2);
    node2->left = node7;
    node2->right = node4;

    runTest(node5, node4, node5);
}

TEST_F(LowestCommonAncestorTests, LeetCodeSample2) {
    Node* node3 = new Node(3);
    Node* node5 = new Node(5, nullptr, nullptr, node3);
    Node* node1 = new Node(1, nullptr, nullptr, node3);
    Node* node6 = new Node(6, nullptr, nullptr, node5);
    Node* node2 = new Node(6, nullptr, nullptr, node5);
    node5->left = node6;
    node5->right = node2;
    Node* node0 = new Node(0, nullptr, nullptr, node1);
    Node* node8 = new Node(8, nullptr, nullptr, node1);
    node1->left = node0;
    node1->right = node8;
    Node* node7 = new Node(7, nullptr, nullptr, node2);
    Node* node4 = new Node(4, nullptr, nullptr, node2);
    node2->left = node7;
    node2->right = node4;

    runTest(node5, node1, node3);
}

TEST_F(LowestCommonAncestorTests, LeetCodeSample3) {
    Node* node1 = new Node(1);
    Node* node2 = new Node(5, nullptr, nullptr, node1);
    node1->left = node2;

    runTest(node1, node2, node1);
}

