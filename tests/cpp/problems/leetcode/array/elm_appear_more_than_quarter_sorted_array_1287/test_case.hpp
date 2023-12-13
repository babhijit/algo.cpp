#pragma once

#include "loader/arrays/load_int_array.hpp"

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>

class TestCase {
private:
    std::vector<int> input;
    int expected;
public:
    explicit TestCase(const std::filesystem::path &file_name) {
        auto json = getJson(file_name);
        input = load_vector(json.at("input").as_array());
        expected = json.at("expected").get_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<int> getInput() {
        return input;
    }

private:
    static boost::json::value getJson(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto json_str = loader.load_file(file_name);
        return boost::json::parse(json_str);
    }

    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for (auto &element: json_array) {
            result.emplace_back(element.get_int64());
        }

        return result;
    }
};
