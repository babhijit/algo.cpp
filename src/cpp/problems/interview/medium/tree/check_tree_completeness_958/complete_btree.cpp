#include "complete_btree.hpp"

#include <queue>


/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::tree::complete_btree {

    bool CompleteBinaryTree::isCompleteTree(TreeNode *root) {
        std::queue<TreeNode *> nodes;

        nodes.push(root);
        bool noPrevSibling {false};
        while (not nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();
            if (not node) {
                noPrevSibling = true;
                continue;
            }

            // once there are no previous siblings, nodes following is not expected
            if(noPrevSibling) {
                return false;
            }

            nodes.push(node->left);
            nodes.push(node->right);
        }

        return true;
    }
}