#ifndef ALGO_CPP_BT_RIGHT_SIDE_VIEW_HPP
#define ALGO_CPP_BT_RIGHT_SIDE_VIEW_HPP

#include <queue>
#include <utility>
#include <vector>

#include <tree_node.hpp>

namespace algo::cpp::problems::bt::right_side_view_199 {

    using namespace algo::cpp::leetcode::ds;

    class BinaryTreeRightSideView {
    public:
        std::vector<int> rightSideView(TreeNode *root);

    private:
        static void add_node_to_level(std::queue<TreeNode *> &level, TreeNode *node);
        static void add_children_to_level(std::queue<TreeNode *> &level, TreeNode *node);
        static std::queue<TreeNode *> process_level(std::queue<TreeNode *> &level, std::vector<int> &right_nodes);
    };

} // right_side_view_199

#endif //ALGO_CPP_BT_RIGHT_SIDE_VIEW_HPP
