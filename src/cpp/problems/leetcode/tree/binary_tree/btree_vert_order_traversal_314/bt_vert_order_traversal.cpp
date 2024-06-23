#include "bt_vert_order_traversal.hpp"

#include <map>
#include <queue>
#include <utility>


namespace algo::cpp { namespace problems::bt::bt_vert_order_traversal_314 {

    using namespace leetcode::ds;

    std::vector<std::vector<int>> BinaryTreeVerticalOrderTraversal::verticalOrder(TreeNode *root) {

        if (not root) {
            return {};
        }

        std::queue<std::pair<int, TreeNode*>> queue;
        queue.emplace(0, root);

        std::map<int, std::vector<int>> columnMap;

        while (not queue.empty()) {
            auto [columnIndex, node] = queue.front();
            queue.pop();

            if (not node) {
                continue;
            }

            auto& columnNodes = columnMap[columnIndex];
            columnNodes.push_back(node->val);

            queue.emplace(columnIndex - 1, node->left);
            queue.emplace(columnIndex + 1, node->right);
        }

        std::vector<std::vector<int>> result;
        result.reserve(columnMap.size());

        for (auto &kv : columnMap) {
            result.push_back(std::move(kv.second));
        }

        return result;
    }

}}
