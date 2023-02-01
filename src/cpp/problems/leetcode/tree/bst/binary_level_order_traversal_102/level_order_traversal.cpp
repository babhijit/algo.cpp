#include "level_order_traversal.hpp"

namespace algo::cpp::problems::bst::binary_level_order_traversal_102 {

    std::vector<std::vector<int>> LevelOrderTraversal::levelOrder(TreeNode* root) {
        Matrix result;

        std::queue<TreeNode*> level;
        if(root)    level.push(root);

        while(!level.empty()) {
            auto next_level = process_level(result, level);
            std::swap(next_level, level);
        }

        return result;
    }

    std::queue<TreeNode *> LevelOrderTraversal::process_level(LevelOrderTraversal::Matrix &result,
                                                              std::queue<TreeNode*> &level) {
        std::queue<TreeNode *> current_level;
        std::vector<int> level_output;

        while(!level.empty()) {
            auto node = level.front();
            level.pop();

            level_output.push_back(node->val);
            push_child_nodes(current_level, node);
        }

        result.push_back(level_output);

        return current_level;
    }

    void LevelOrderTraversal::push_child_nodes(std::queue<TreeNode *> &level, TreeNode *node) {
        if(node->left)      push_node(level, node->left);
        if(node->right)     push_node(level, node->right);
    }

    void LevelOrderTraversal::push_node(std::queue<TreeNode *> &level, TreeNode *node) {
        level.push(node);
    }
}
