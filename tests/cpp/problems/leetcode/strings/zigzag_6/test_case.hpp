#pragma once

#include "loader/json_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <fstream>
#include <string>


class TestCase {
private:

    std::string s;
    std::int32_t numRows;
    std::string expected;

public:
    explicit TestCase(std::filesystem::path const &path) {
        auto loader = JsonLoader();
        auto json = loader.loadJson(path);
        s = json.at("s").as_string().c_str();
        numRows = json.at("numRows").as_int64();
        expected = json.at("expected").as_string().c_str();
    }

    [[nodiscard]] std::string const &getS() const {
        return s;
    }

    [[nodiscard]] std::int32_t const &getNumRows() const {
        return numRows;
    }

    [[nodiscard]] std::string getExpected() const {
        return expected;
    }
};

