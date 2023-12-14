#pragma once

#include "loader/arrays/load_int_array.hpp"

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>


class TestCase {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;
private:
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> expected;

public:
    explicit TestCase(const std::filesystem::path &file_name) {
        auto json = getJson(file_name);
        input = load_matrix(json.at("input").as_array());
        expected = load_matrix(json.at("expected").as_array());
    }

    [[nodiscard]] Matrix<int> getExpected() const {
        return expected;
    }

    [[nodiscard]] Matrix<int> getInput() {
        return input;
    }

private:
    static boost::json::value getJson(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto json_str = loader.load_file(file_name);
        return boost::json::parse(json_str);
    }

    static Matrix<int> load_matrix(boost::json::array &array) {
        Matrix<int> result;
        for (auto &element: array) {
            std::vector<int> row = loadVector(element.as_array());
            result.emplace_back(std::move(row));
        }

        return result;
    }

    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for (auto &element: json_array) {
            result.emplace_back(element.get_int64());
        }

        return result;
    }
};

