#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>


#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> tops;
    std::vector<int> bottoms;
    int expected;

public:
    TestCase(boost::json::value&& json) {
        tops = loadVector(json.at("tops").as_array());
        bottoms = loadVector(json.at("bottoms").as_array());
        expected = json.at("result").as_int64();
    }

    int getExpected() const {
        return expected;
    }

    std::vector<int> getTops() {
        return tops;
    }

    std::vector<int> getBottoms() {
        return bottoms;
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
