#pragma once

#include "loader/json_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <fstream>
#include <string>


class TestCase {
private:

    std::string s;
    std::int32_t expected;

public:
    explicit TestCase(std::filesystem::path const &path) {
        auto loader = JsonLoader();
        auto json = loader.loadJson(path);
        s = json.at("s").as_string().c_str();
        expected = static_cast<std::int32_t>(json.at("expected").as_int64());
    }

    [[nodiscard]] std::string const &getS() const {
        return s;
    }

    [[nodiscard]] std::int32_t getExpected() const {
        return expected;
    }
};

