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
    std::vector<int> expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums = loadVector(json.at("nums").as_array());
        target = json.at("target").as_int64();
        expected = loadVector(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<int> getExpected() const {
        return expected;
    }


    [[nodiscard]] std::vector<int> getNums() const {
        return nums;
    }

    [[nodiscard]] int getTarget() const {
        return target;
    }

private:
    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};
