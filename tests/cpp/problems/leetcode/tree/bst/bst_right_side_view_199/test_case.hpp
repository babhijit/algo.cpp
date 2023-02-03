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
    std::vector<int> expected;

    BaseLoader loader;
    LoadBst bst_loader;


public:
    explicit TestCase(std::filesystem::path file) {
        auto json_str = loader.load_file(file);
        auto json = boost::json::parse(json_str);

        auto bst_input = json.at("input").as_string().c_str();
        input = load_bst(bst_input);
        expected = load_vector(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<int> getExpected() const {
        return expected;
    }

    TreeNode* getInput() {
        return input;
    }

private:
    TreeNode* load_bst(std::string bst_input) {
        return bst_loader.load_bst(std::move(bst_input));
    }

    static std::vector<int> load_vector(boost::json::array json_array) {

        std::vector<int> result;
        for (auto &element: json_array) {
            result.emplace_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
