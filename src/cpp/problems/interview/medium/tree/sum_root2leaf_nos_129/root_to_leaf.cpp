#include "root_to_leaf.hpp"

/**
 * Time Complexity: O(N)
 * Space Complexity: O(H) H->height of the tree
 */

namespace algo::interview::medium::tree::root2leaf {

    using namespace algo::cpp::leetcode::ds;

    bool isLeafNode(TreeNode* node) {
        return (not node->left) and (not node->right);
    }

    int preOrderSumNumbers(int number, TreeNode* node) {
        if (not node) {
            return 0;
        }

        number = 10*number + node->val;

        if (isLeafNode(node)) {
            return number;
        }

        return preOrderSumNumbers(number, node->left) +
               preOrderSumNumbers(number, node->right);
    }

    int Root2Leaf::sumNumbers(algo::cpp::leetcode::ds::TreeNode *root) {
        return preOrderSumNumbers(0, root);
    }
}