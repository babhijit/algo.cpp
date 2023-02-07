#include "flatten_binary_tree_to_list.hpp"


namespace algo::cpp::problems::bt::flatten_binary_tree_to_list {

    void FlattenBinaryTreeToList::flatten(TreeNode *root) {
        preorder(root);
    }

    FlattenBinaryTreeToList::HeadTailPair FlattenBinaryTreeToList::preorder(TreeNode *node) {
        if (!node) {
            return {nullptr, nullptr};
        }

        // Edge Case: Leaf Node
        if (is_leaf(node)) {
            return {node, node};
        }

        auto [left_head, left_tail] = preorder(node->left);
        auto [right_head, right_tail] = preorder(node->right);

        node->left = nullptr;

        // Edge Case: No Right Branch
        if (!right_head) {
            node->right = left_head;
            return {node, left_tail};
        }

        // Edge Case: No Left Branch
        if (!left_head) {
            node->right = right_head;
            return {node, right_tail};
        }

        node->right = left_head;
        left_tail->right = right_head;
        return {node, right_tail};
    }

    bool FlattenBinaryTreeToList::is_leaf(TreeNode *node) {
        return !node->right && !node->left;
    }


} // flatten_binary_tree_to_list