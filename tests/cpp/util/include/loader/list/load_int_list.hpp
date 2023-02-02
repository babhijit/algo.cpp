#ifndef ALGO_CPP_LOAD_INT_LIST_HPP
#define ALGO_CPP_LOAD_INT_LIST_HPP

#include <filesystem>
#include <string>
#include <vector>

#include <list_node.hpp>

#include "loader/base_loader.hpp"

namespace algo::cpp::ds::tests::utils {

    using namespace algo::cpp::leetcode::ds;

    class LoadIntList : public BaseLoader {
    public:
        ListNode* operator()(std::string input);

        ListNode* load_list(std::vector<int> values);
    };

} // utils

#endif //ALGO_CPP_LOAD_INT_LIST_HPP
