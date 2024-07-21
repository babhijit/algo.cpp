#include "lowest_common_ancestor.hpp"

#include <deque>
#include <vector>

namespace algo::interview::medium::tree::lowest_common_ancestor {

    using Level = std::vector<TreeNode*>;
    using TreeDepth = std::vector<Level>;

    TreeDepth getDepth(TreeNode* root) {
        TreeDepth depth;
        Level currentLevel;
        currentLevel.push_back(root);

        while (not currentLevel.empty()) {
            depth.push_back(currentLevel);
            Level nextLevel;
            for (auto node: currentLevel) {
                if (node->left)     nextLevel.push_back(node->left);
                if (node->right)    nextLevel.push_back(node->right);
            }
            currentLevel.swap(nextLevel);
        }

        return depth;
    }

    std::pair<int, int> getLevelIndices(TreeDepth const& treeDepth, TreeNode* p, TreeNode* q) {
        int pIndex {-1}, qIndex{-1};

        int depth{0};
        for (auto& lvl: treeDepth) {
            for (auto& node: lvl) {
                if (pIndex < 0) {
                    if (node == p) {
                        pIndex = depth;
                    }
                }
                if (qIndex < 0) {
                    if (node == q) {
                        qIndex = depth;
                    }
                }
                if (pIndex >= 0 and qIndex >= 0) {
                    return {pIndex, qIndex};
                }
            }
            ++depth;
        }

        return {pIndex, qIndex};
    }

    TreeNode* getParentNode(Level const& level, TreeNode* node) {
        for(auto node: level) {
            if ((node->left = node) or (node->right == node))
                return node;
        }
        return {};
    }

    TreeNode* lca(TreeDepth const& treeDepth, TreeNode* p, int pIndex, TreeNode* q, int qIndex) {
        TreeNode *pParent = p;
        TreeNode *qParent = q;

        // we go up a level (for the original)

        while (pParent != qParent) {
            if (pIndex >= qIndex) {
                pParent = getParentNode(treeDepth[pIndex - 1], pParent);
            }
            if (qIndex >= pIndex) {
                qParent = getParentNode(treeDepth[qIndex - 1], pParent);
            }
            --pIndex;
            --qIndex;
        }

        // both parents now point to the same parent so we can return any of pParent or qParent
        return pParent;
    }


    TreeNode *LowestCommonAncestor::lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode *q) {
        auto depth = getDepth(root);
        auto [pIndex, qIndex] = getLevelIndices(depth, p, q);
        return lca(depth, p, pIndex, q, qIndex);
    }
}