#include "bt_vert_order_traversal.hpp"

#include <queue>
#include <unordered_map>
#include <utility>


namespace algo::cpp { namespace problems::bt::bt_vert_order_traversal_314 {

    using namespace leetcode::ds;

    std::vector<std::vector<int>> BinaryTreeVerticalOrderTraversal::verticalOrder(TreeNode *root) {

        if (not root) {
            return {};
        }

        std::queue<std::pair<int, TreeNode*>> queue;
        queue.emplace(0, root);

        std::unordered_map<int, std::vector<int>> columnMap;

        int minColumn{}, maxColumn{};

        while (not queue.empty()) {
            auto [columnIndex, node] = queue.front();
            queue.pop();

            if (not node) {
                continue;
            }

            auto& columnNodes = columnMap[columnIndex];
            columnNodes.push_back(node->val);

            minColumn = std::min(minColumn, columnIndex);
            maxColumn = std::max(maxColumn, columnIndex);

            queue.emplace(columnIndex - 1, node->left);
            queue.emplace(columnIndex + 1, node->right);
        }

        std::vector<std::vector<int>> result;
        result.reserve(columnMap.size());

        for (int i = minColumn; i <= maxColumn; ++i) {
            result.push_back(std::move(columnMap[i]));
        }

        return result;
    }

}}
