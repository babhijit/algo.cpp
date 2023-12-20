#pragma once

#include "loader/arrays/load_int_array.hpp"

#include "loader/base_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <string>
#include <vector>

class TestCase {
private:
    std::vector<int> prices;
    int money;
    int expected;
public:
    explicit TestCase(const std::filesystem::path &file_name) {
        auto json = getJson(file_name);
        prices = loadVector(json.at("prices").as_array());
        money = json.at("money").as_int64();
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] std::vector<int>& getPrices() {
        return prices;
    }

    [[nodiscard]] int getMoney() {
        return money;
    }

    [[nodiscard]] int getExpected() {
        return expected;
    }

private:
    static boost::json::value getJson(const std::filesystem::path &file_name) {
        BaseLoader loader;
        auto json_str = loader.load_file(file_name);
        return boost::json::parse(json_str);
    }

    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for (auto &element: json_array) {
            result.emplace_back(element.get_int64());
        }

        return result;
    }
};
