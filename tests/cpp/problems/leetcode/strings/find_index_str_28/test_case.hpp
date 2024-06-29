#pragma once

#include <boost/json.hpp>

#include "loader/base_loader.hpp"

#include <utility>
#include <vector>


class TestCase {
private:
    std::string haystack;
    std::string needle;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);

        auto parsed_data = boost::json::parse(json_str);
        const boost::json::object& json_object = parsed_data.as_object();

        haystack = json_object.at("haystack").as_string();
        needle = json_object.at("needle").as_string();
        expected = static_cast<int>(json_object.at("expected").as_int64());
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::string getHaystack() const {
        return haystack;
    }

    [[nodiscard]] std::string getNeedle() const {
        return needle;
    }

};
