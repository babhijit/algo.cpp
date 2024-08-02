#include "bst2dll.hpp"

#include <utility>

/**
 * Space Complexity: O(N)
 * Time Complexity: O(N)
 */

namespace algo::interview::medium::tree::bst2dll {

    // this will contain the left and right edges of the subtree
    using Edges = std::pair<TreeNode*, TreeNode*>;

    Edges inorder(TreeNode* node) {
        if (not node) { return {nullptr, nullptr}; }

        auto leftSubtree = node->left;
        auto rightSubtree = node->right;

        auto [leftMostLeftEdge, leftMostRightEdge] = inorder(leftSubtree);
        auto [rightMostLeftEdge, rightMostRightEdge] = inorder(rightSubtree);

        node->left = leftMostRightEdge;
        if (leftMostRightEdge) {
            leftMostRightEdge->right = node;
        }
        if (not leftMostLeftEdge) {
            leftMostLeftEdge = node;
        }

        node->right = rightMostLeftEdge;
        if (rightMostLeftEdge) {
            rightMostLeftEdge->left = node;
        }
        if (not rightMostRightEdge) {
            rightMostRightEdge = node;
        }

        return {leftMostLeftEdge, rightMostRightEdge};
    }

    TreeNode *Bst2Dll::treeToDoublyList(TreeNode *root) {
        auto [leftEdge, rightEdge] = inorder(root);
        return leftEdge;
    }
}