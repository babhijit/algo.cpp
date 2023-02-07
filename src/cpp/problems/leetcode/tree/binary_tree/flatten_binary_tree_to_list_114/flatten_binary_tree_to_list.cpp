#include "flatten_binary_tree_to_list.hpp"


namespace algo::cpp::problems::bt::flatten_binary_tree_to_list {

    void FlattenBinaryTreeToList::flatten(TreeNode *root) {
        preorder(root);
    }

    TreeNode *FlattenBinaryTreeToList::preorder(TreeNode *node) {

        if (is_null(node) || is_leaf(node)) {
            return node;
        }

        auto left_tail = preorder(node->left);
        auto right_tail = preorder(node->right);

        auto left_head = node->left;
        node->left = nullptr;

        // Edge Case: No Right Branch
        if (!right_tail) {
            node->right = left_head;
            return left_tail;
        }

        // Edge Case: No Left Branch
        if (!left_head) {
            return right_tail;
        }

        left_tail->right = node->right;
        node->right = left_head;
        return right_tail;
    }

    bool FlattenBinaryTreeToList::is_leaf(TreeNode *node) {
        return is_null(node->right) && is_null(node->left);
    }

    bool FlattenBinaryTreeToList::is_null(TreeNode *node) {
        return node == nullptr;
    }


} // flatten_binary_tree_to_list