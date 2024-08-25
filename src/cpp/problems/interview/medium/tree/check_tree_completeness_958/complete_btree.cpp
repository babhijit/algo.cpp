#include "complete_btree.hpp"

#include <queue>


/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::tree::complete_btree {

    inline bool isLeafNode(TreeNode* node) {
        return not node->left and not node->right;
    }

    inline bool isNodeIncomplete(TreeNode* node) {
        return not node->left and node->right;
    }

    bool isLevelComplete(std::queue<TreeNode *> &nodesAtLevel) {
        std::queue<TreeNode *> nextLevel;

        bool prevNodeHasBothChildren{true};
        while (not nodesAtLevel.empty()) {
            auto node = nodesAtLevel.front();
            nodesAtLevel.pop();

            // if the previous node has no children
            // then the current node should not have any children for tree completeness
            if (not prevNodeHasBothChildren) {
                if (node->left or node->right) {
                    return false;
                }
            }

            if (isLeafNode(node)) {
                prevNodeHasBothChildren = false;
                continue;
            }

            if (isNodeIncomplete(node)) {
                return false;
            }

            prevNodeHasBothChildren = node->left and node->right;
            nextLevel.push(node->left);
            if (node->right) {
                nextLevel.push(node->right);
            }
        }

        std::swap(nextLevel, nodesAtLevel);
        return true;
    }


    bool CompleteBinaryTree::isCompleteTree(TreeNode *root) {
        std::queue<TreeNode *> nodes;

        nodes.push(root);
        int level = 0;
        bool canProcessNextLevel{true};
        while (not nodes.empty()) {
            if (not canProcessNextLevel) {
                return false;
            }

            // we should go to next level only if the previous level had all children
            auto expectedLevelCompleteNodeCount = 1 << level;
            if (expectedLevelCompleteNodeCount != nodes.size()) {
                canProcessNextLevel = false;
            }

            if (not isLevelComplete(nodes)) {
                return false;
            }

            ++level;
        }

        return true;
    }
}