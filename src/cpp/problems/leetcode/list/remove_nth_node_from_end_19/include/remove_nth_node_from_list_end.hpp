#ifndef ALGO_CPP_REMOVE_NTH_NODE_FROM_LIST_END_HPP
#define ALGO_CPP_REMOVE_NTH_NODE_FROM_LIST_END_HPP

#include <list_node.hpp>

namespace algo::problems::leetcode::list::remove_nth_node_from_list_end {

    using namespace algo::cpp::leetcode::ds;

    class RemoveNthNodeFromListEnd {
    public:
        ListNode* removeNthNodeFromEnd(ListNode* head, int n);
    };

} // remove_nth_node_from_list_end

#endif //ALGO_CPP_REMOVE_NTH_NODE_FROM_LIST_END_HPP
