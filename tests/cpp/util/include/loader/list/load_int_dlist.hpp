#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include <dlist_node.hpp>

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

namespace algo::cpp::ds::tests::utils {

    using namespace algo::cpp::leetcode::ds;

    class LoadIntDList : public BaseLoader {
    public:
        DListNode* operator()(std::string input);
        DListNode* operator()(boost::json::array& array);

        DListNode* load_dlist(std::vector<int> values);
    };

} // utils

