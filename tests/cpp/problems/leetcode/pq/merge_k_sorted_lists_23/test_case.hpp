#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>
#include <vector>

#include <boost/json.hpp>

#include "list_node.hpp"

#include "loader/base_loader.hpp"

#include "loader/list/load_int_list.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<ListNode*> input;
    ListNode* expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);

        input = load_lists(json.at("input").as_array());
        expected = load_list(json.at("expected").as_array());
    }


    [[nodiscard]] ListNode* getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<ListNode*> getInput() const {
        return input;
    }

    static ListNode* load_list(std::vector<int> values) {
        LoadIntList loader;
        auto input = loader.load_list(std::move(values));
        return input;
    }

    static std::vector<ListNode*> load_lists_from_vector(std::vector<std::vector<int>> values) {
        std::vector<ListNode*> lists;
        for (auto& v: values) {
            auto list = load_list(v);
            lists.push_back(list);
        }

        return lists;
    }

private:
    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }

    static ListNode* load_list(boost::json::array json_array) {
        auto values = loadVector(std::move(json_array));
        return load_list(std::move(values));
    }

    static std::vector<ListNode*> load_lists(boost::json::array json_array) {
        std::vector<ListNode*> lists;

        for(auto &array_element: json_array) {
            ListNode* list = load_list(array_element.as_array());
            lists.push_back(list);
        }

        return lists;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
