#pragma once

#include <string>
#include <utility>

#include <boost/json.hpp>


#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    TreeNode *input;
    std::string expected;

public:
    explicit TestCase(std::filesystem::path const &file) {
        auto json = getJson(file);
        input = loadBst(json);
        expected = json.at("expected").as_string().c_str();
    }

    [[nodiscard]] std::string getExpected() const {
        return expected;
    }

    [[nodiscard]] TreeNode *getInput() {
        return input;
    }

private:
    static boost::json::value getJson(std::filesystem::path const &file) {
        BaseLoader loader;
        auto json_str = loader.load_file(file);
        return boost::json::parse(json_str);
    }

    static TreeNode *loadBst(boost::json::value &json) {
        auto bstInput = json.at("input").as_string().c_str();
        return loadBst(bstInput);
    }

public:
    static TreeNode* loadBst(std::string const& bstInput) {
        LoadBst bst_loader;
        return bst_loader.load_bst(bstInput);
    }
};
