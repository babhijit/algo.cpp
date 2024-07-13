#pragma once

#include "loader/arrays/load_int_array.hpp"
#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <string>
#include <vector>


using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    int n;
    std::vector<std::string> expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        n = static_cast<int>(json.at("n").as_int64());
        expected = loadVector(json.at("expected").as_array());
    }

    int getN() const {
        return n;
    }

    std::vector<std::string> getExpected() const {
        return expected;
    }

private:
    static std::vector<std::string> loadVector(boost::json::array json_array) {
        std::vector<std::string> result;
        for (auto &element: json_array) {
            result.push_back(element.as_string().c_str());
        }
        return result;
    }

};