#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


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
    TreeNode* input;
    TreeNode* expected;


public:
    explicit TestCase(std::filesystem::path file) {
        BaseLoader loader;
        auto json_str = loader.load_file(file);
        auto json = boost::json::parse(json_str);

        auto bst_input = json.at("input").as_string().c_str();
        input = load_bst(bst_input);
        auto bst_expected = json.at("expected").as_string().c_str();
        expected = load_bst(bst_expected);;
    }

    [[nodiscard]] TreeNode* getExpected() const {
        return expected;
    }

    [[nodiscard]] TreeNode* getInput() const {
        return input;
    }

public:
    static TreeNode* load_bst(std::string bst_input) {
        LoadBst bst_loader;
        return bst_loader.load_bst(std::move(bst_input));
    }

};


#endif //ALGO_CPP_TEST_CASE_HPP
