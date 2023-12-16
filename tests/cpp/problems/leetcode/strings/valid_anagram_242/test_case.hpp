#pragma once

#include "loader/json_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>
#include <fstream>
#include <string>


class TestCase {
private:

    std::string s;
    std::string t;
    bool expected;

public:
    explicit TestCase(std::filesystem::path const &path) {
        auto loader = JsonLoader();
        auto json = loader.loadJson(path);
        s = json.at("s").as_string().c_str();
        t = json.at("t").as_string().c_str();
        expected = json.at("expected").as_bool();
    }

    [[nodiscard]] std::string const &getS() const {
        return s;
    }

    [[nodiscard]] std::string const &getT() const {
        return t;
    }

    [[nodiscard]] bool getExpected() const {
        return expected;
    }
};

