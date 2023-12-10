#pragma once

#include <boost/json.hpp>

#include "loader/base_loader.hpp"

#include <string>
#include <utility>
#include <vector>


class TestCase {
private:
    std::string num;
    std::string expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        auto json = load_json(testcase);
        const boost::json::object &json_object = json.as_object();

        for (const auto &[key, value]: json_object) {

            if (key == "num") {
                assert(value.is_string() && "Expected String");
                num = value.as_string().c_str();
            } else if (key == "expected") {
                assert(value.is_string() && "Expected Number String");
                expected = value.as_string();
            } else {
                assert(false && "Unknown key");
            }
        }
    }

    [[nodiscard]] std::string getExpected() const {
        return expected;
    }

    [[nodiscard]] const std::string &getNum() const {
        return num;
    }

private:

    static boost::json::value load_json(const std::filesystem::path &fileName) {
        BaseLoader loader;
        auto json_str = loader.load_file(fileName);

        return boost::json::parse(json_str);
    }

};
