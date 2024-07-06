#pragma once

#include "loader/arrays/load_int_array.hpp"

#include "tree_node.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"
#include "lc_file_utils.hpp"
#include <boost/json.hpp>

#include <string>
#include <vector>

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    TreeNode* root;
    bool expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        auto rootNodes = loadStrVector(json.at("root").as_array());
        LoadBst bst_loader;
        root = bst_loader.load_bst(rootNodes);
        expected = json.at("expected").as_bool();
    }

    [[nodiscard]] bool getExpected() {
        return expected;
    }

    [[nodiscard]] TreeNode* getRoot(){
        return root;
    }

private:
    static std::vector<int> loadVector(boost::json::array json_array) {

        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(static_cast<int>(element.get_int64()));
        }

        return result;
    }
    
    static std::vector<std::string> loadStrVector(boost::json::array json_array) {

        std::vector<std::string> result;
        for(auto &element: json_array) {
            result.emplace_back(element.get_string().c_str());
        }

        return result;
    }
};
