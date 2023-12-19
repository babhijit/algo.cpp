#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>


#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:

    std::vector<std::string> operations;
    std::vector<std::vector<std::string>> inputs;
    std::vector<std::string> expected;

public:
    explicit TestCase(boost::json::value&& json) {
        loadVector(json.at("operations").as_array(), operations);
        loadVector(json.at("expected").as_array(), expected);

    }

    std::vector<std::string> getExpected() const {
        return expected;
    }

    std::vector<std::vector<std::string>> getInputs() {
        return inputs;
    }


private:
    void loadVector(boost::json::array json_array, std::vector<std::string>& result) {
        for(auto &element: json_array) {
            result.emplace_back(element.get_string());
        }
    }

    void loadVector(boost::json::array json_array, std::vector<int>& result) {
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }
    }
};
