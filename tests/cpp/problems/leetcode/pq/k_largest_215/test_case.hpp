#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>
#include <vector>

#include <boost/json.hpp>

#include "loader/list/load_int_list.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<int> input;
    int k;
    int expected;

public:
    explicit TestCase(boost::json::value&& json) {
        input = load_vector(json.at("input").as_array());
        k = json.at("k").as_int64();
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getK() const {
        return k;
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<int> getInput() const {
        return input;
    }


private:
    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
