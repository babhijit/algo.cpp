#pragma once

#include "loader/arrays/load_int_array.hpp"

#include <boost/json.hpp>

#include <string>
#include <vector>

namespace algo::problems::leetcode::hastable::uniq_occurences::test {

    class TestCase {
    private:
        std::vector<int> input;
        bool expected;

    public:
        TestCase(boost::json::value &&json) {
            input = loadVector(json.at("input").as_array());
            expected = json.at("expected").as_bool();
        }

        bool getExpected() const {
            return expected;
        }

        std::vector<int> getInput() {
            return input;
        }


    private:
        std::vector<int> loadVector(boost::json::array &json_array) {
            std::vector<int> result;
            for (auto &element: json_array) {
                result.push_back(element.get_int64());
            }

            return result;
        }
    };

}