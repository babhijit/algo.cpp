#include "lowest_common_ancestor.hpp"

#include <deque>
#include <unordered_set>
#include <vector>
#include <unordered_map>

namespace algo::interview::medium::tree::lowest_common_ancestor {

    TreeNode *LowestCommonAncestor::lowestCommonAncestor(TreeNode* root, TreeNode *p, TreeNode *q) {
        std::deque<TreeNode*> stack;
        std::unordered_map<TreeNode*, TreeNode*> parent;

        parent[root] = nullptr;
        stack.push_front(root);

        while (not parent.contains(p) or not parent.contains(q)) {
            auto node = stack.back();
            stack.pop_back();

            if (node->left) {
                parent[node->left] = node;
                stack.push_front(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                stack.push_front(node->right);
            }
        }

        std::unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        while (not ancestors.contains(q)) {
            q = parent[q];
        }

        return q;
    }
}