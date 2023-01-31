#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>


#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> input;
    int target;
    bool expected;

public:
    TestCase(boost::json::value&& json) {
        input = load_vector(json.at("input").as_array());
        target = json.at("target").as_int64();
        expected = json.at("expected").as_bool();
    }

    bool getExpected() const {
        return expected;
    }

    std::vector<int> getInput() {
        return input;
    }

    int getTarget() {
        return target;
    }

private:
    std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
