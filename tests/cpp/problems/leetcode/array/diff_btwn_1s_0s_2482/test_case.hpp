#pragma once

#include "loader/arrays/load_int_array.hpp"

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>

using IntMatrix = std::vector<std::vector<int>>;

class TestCase {
private:
    IntMatrix input;
    IntMatrix expected;
public:
    explicit TestCase(const std::filesystem::path &file_name) {
        auto json = getJson(file_name);
        input = loadMatrix(json.at("input").as_array());
        expected = loadMatrix(json.at("expected").as_array());
    }

    [[nodiscard]] IntMatrix& getExpected() {
        return expected;
    }

    [[nodiscard]] IntMatrix& getInput() {
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

    static IntMatrix loadMatrix(boost::json::array json_array) {
        IntMatrix result;
        for (auto &element: json_array) {
            result.emplace_back(load_vector(element.as_array()));
        }

        return result;
    }
};

