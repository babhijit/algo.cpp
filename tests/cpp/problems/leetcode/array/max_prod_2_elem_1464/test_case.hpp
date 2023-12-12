#pragma once

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <vector>

class TestCase {
private:
    std::vector<int> input;
    int expected;

public:

    TestCase(const std::filesystem::path &testcase) {
        auto json = loadJson(testcase);
        input = load_vector(json.at("input").as_array());
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<int> getInput() {
        return input;
    }

private:
    boost::json::value loadJson(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        return boost::json::parse(json_str);
    }

    std::vector<int> load_vector(boost::json::array &array) {
        std::vector<int> result;
        for (auto &element: array) {
            result.emplace_back(element.get_int64());
        }

        return result;
    }

};
