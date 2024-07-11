#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> nums;
    int target;
    std::vector<std::vector<int>> expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums = load_vector(json.at("nums").as_array());
        target = static_cast<int>(json.at("target").as_int64());
        expected = load_matrix(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<std::vector<int>> getExpected() const {
        return expected;
    }


    [[nodiscard]] std::vector<int> getNums() const {
        return nums;
    }

    [[nodiscard]] int getTarget() const {
        return target;
    }

private:
    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(static_cast<int>(element.get_int64()));
        }

        return result;
    }

    static std::vector<std::vector<int>> load_matrix(boost::json::array json_array) {
        std::vector<std::vector<int>> result;
        for(auto &element: json_array) {
            result.push_back(load_vector(element.as_array()));
        }

        return result;
    }
};
