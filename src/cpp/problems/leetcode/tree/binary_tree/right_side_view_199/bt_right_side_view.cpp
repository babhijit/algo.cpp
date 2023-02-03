#include "include/bt_right_side_view.hpp"

#include <stack>

namespace algo::cpp::problems::bt::right_side_view_199 {

    std::vector<int> BinaryTreeRightSideView::rightSideView(TreeNode *root) {
        std::vector<int> result;

        std::queue<TreeNode *> level;
        add_node_to_level(level, root);

        while (!level.empty()) {
            auto next_level = process_level(level, result);
            std::swap(level, next_level);
        }

        return result;

    }

    void BinaryTreeRightSideView::add_node_to_level(std::queue<TreeNode *> &level, TreeNode *node) {
        if (node) {
            level.push(node);
        }
    }

    void BinaryTreeRightSideView::add_children_to_level(std::queue<TreeNode *> &level,
                                                        TreeNode *node) {
        if (node) {
            add_node_to_level(level, node->left);
            add_node_to_level(level, node->right);
        }
    }

    std::queue<TreeNode *> BinaryTreeRightSideView::process_level(std::queue<TreeNode *> &level,
                                                                  std::vector<int> &right_nodes) {

        std::queue<TreeNode *> next_level;
        if (level.empty()) {
            return next_level;
        }

        TreeNode *node = nullptr;
        while (!level.empty()) {
            node = level.front();
            level.pop();

            add_children_to_level(next_level, node);
        }

        if (node) {
            right_nodes.push_back(node->val);
        }


        return next_level;
    }

} // right_side_view_199