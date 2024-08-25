#pragma once

#include <string>
#include <utility>
#include <vector>

#include <boost/json.hpp>


#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;


class TestCase {
private:
    TreeNode* root_;
    bool expected_;

    BaseLoader loader;
    LoadBst bst_loader;

public:
    explicit TestCase(std::filesystem::path file) {
        auto json_str = loader.load_file(file);
        auto json = boost::json::parse(json_str);

        auto bst_input = json.at("root").as_string().c_str();
        root_ = load_bst(bst_input);
        expected_ =json.at("expected").as_bool();
    }

    explicit TestCase(std::string treeNodes, bool expected) {
        root_ = load_bst(std::move(treeNodes));
        expected_ = expected;
    }

    [[nodiscard]] bool getExpected() const {
        return expected_;
    }

    TreeNode* getRoot() {
        return root_;
    }

private:
    TreeNode* load_bst(std::string bst_input) {
        return bst_loader.load_bst(std::move(bst_input));
    }
};
