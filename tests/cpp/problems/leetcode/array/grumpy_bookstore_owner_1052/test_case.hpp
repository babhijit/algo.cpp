#pragma once

#include "loader/arrays/load_int_array.hpp"

#include <boost/json.hpp>

#include <string>
#include <vector>

class TestCase {
private:
    std::vector<int> customers;
    std::vector<int> grumpy;
    int minutes;
    int expected;

public:
    explicit TestCase(boost::json::value &&json) {
        customers = loadVector(json.at("customers").as_array());
        grumpy = loadVector(json.at("grumpy").as_array());
        minutes = static_cast<int>(json.at("minutes").as_int64());
        expected = static_cast<int>(json.at("expected").as_int64());
    }

    std::vector<int> getCustomers() {
        return customers;
    }

    std::vector<int> getGrumpy() {
        return grumpy;
    }

    int getMinutes() {
        return minutes;
    }

    int getExpected() {
        return expected;
    }

private:
    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for (auto &element: json_array) {
            result.push_back(static_cast<int>(element.get_int64()));
        }

        return result;
    }
};
