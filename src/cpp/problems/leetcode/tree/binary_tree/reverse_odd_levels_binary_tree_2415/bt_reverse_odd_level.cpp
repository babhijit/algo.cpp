#include "bt_reverse_odd_level.hpp"


namespace algo::cpp::problems::bt::reverse_odd_levels {

    TreeNode *ReverseOddLevelsBT::reverseOddLevels(TreeNode *root) {
        if (!root) return nullptr;

        std::queue<TreeNode *> nodes;
        nodes.push(root);

        auto current_level = 0;

        while (!nodes.empty()) {
            auto next_level = process_current_level(current_level, nodes);
            std::swap(nodes, next_level);
            ++current_level;
        }


        return root;
    }

    std::queue<TreeNode *> ReverseOddLevelsBT::process_current_level(int level, std::queue<TreeNode *> &nodes) {
        if (is_odd(level))
            return process_odd_level(nodes);
        else
            return process_even_level(nodes);
    }

    std::queue<TreeNode *> ReverseOddLevelsBT::process_even_level(std::queue<TreeNode *> &nodes) {
        std::queue<TreeNode *> next_level;

        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();

            add_children_to_queue(next_level, node);
        }

        return next_level;
    }

    std::queue<TreeNode *> ReverseOddLevelsBT::process_odd_level(std::queue<TreeNode *> &nodes) {
        std::vector<TreeNode*> current_level_nodes;

        std::queue<TreeNode *> next_level;

        while (!nodes.empty()) {
            auto node = nodes.front();
            nodes.pop();

            current_level_nodes.push_back(node);

            add_children_to_queue(next_level, node);
        }

        auto const N = current_level_nodes.size();
        for (int i = 0; i < N / 2; ++i) {
            std::swap(current_level_nodes[i]->val, current_level_nodes[N - i - 1]->val);
        }

        return next_level;
    }

    void ReverseOddLevelsBT::add_node_to_queue(std::queue<TreeNode *> &q, TreeNode *node) {
        if(node) {
            q.push(node);
        }
    }

    void ReverseOddLevelsBT::add_children_to_queue(std::queue<TreeNode *> &q, TreeNode *node) {
        if(node) {
            add_node_to_queue(q, node->left);
            add_node_to_queue(q, node->right);
        }
    }

}
