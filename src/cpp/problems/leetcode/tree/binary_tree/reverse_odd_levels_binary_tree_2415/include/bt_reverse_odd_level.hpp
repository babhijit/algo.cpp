#ifndef ALGO_CPP_REVERSE_ODD_LEVELS_BINARY_TREE_HPP
#define ALGO_CPP_REVERSE_ODD_LEVELS_BINARY_TREE_HPP

#include <utility>

#include <tree_node.hpp>


namespace algo::cpp::problems::bt::reverse_odd_levels {

    using namespace leetcode::ds;

    class ReverseOddLevelsBT {

    public:
        TreeNode *reverseOddLevels(TreeNode *root);

    private:

        std::queue<TreeNode *> process_current_level(int level, std::queue<TreeNode *> &nodes);

        std::queue<TreeNode *> process_odd_level(std::queue<TreeNode *> &nodes);
        std::queue<TreeNode *> process_even_level(std::queue<TreeNode *> &nodes);

        void add_node_to_queue(std::queue<TreeNode *> &q, TreeNode* node);
        void add_children_to_queue(std::queue<TreeNode *> &q, TreeNode* node);

        inline bool is_odd(int level) const { return level & 1; }

    };
}

#endif //ALGO_CPP_REVERSE_ODD_LEVELS_BINARY_TREE_HPP
