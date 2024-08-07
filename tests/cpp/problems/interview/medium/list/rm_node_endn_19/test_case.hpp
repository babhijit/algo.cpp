#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>
#include <vector>

#include <boost/json.hpp>

#include <list_node.hpp>

#include "loader/list/load_int_list.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    ListNode* input;
    int n;
    ListNode* expected;

public:
    explicit TestCase(const std::filesystem::directory_entry& testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = load_list(json.at("input").as_array());
        n = json.at("n").as_int64();
        expected = load_list(json.at("expected").as_array());
    }

    [[nodiscard]] int getN() const {
        return n;
    }

    [[nodiscard]] ListNode* getExpected() const {
        return expected;
    }

    [[nodiscard]] ListNode* getInput() const {
        return input;
    }

    static ListNode* load_list(std::vector<int> values) {
        LoadIntList loader;
        auto input = loader.load_list(std::move(values));
        return input;
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
};


#endif //ALGO_CPP_TEST_CASE_HPP
