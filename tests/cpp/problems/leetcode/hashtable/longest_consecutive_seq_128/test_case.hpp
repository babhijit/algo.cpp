#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>


#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> input;
    int expected;

public:
    TestCase(boost::json::value&& json) {
        input = loadVector(json.at("input").as_array());
        expected = json.at("expected").as_int64();
    }

    int getExpected() const {
        return expected;
    }

    std::vector<int> getInput() {
        return input;
    }


private:
    std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
