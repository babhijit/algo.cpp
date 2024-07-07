#pragma once

#include "loader/arrays/load_int_array.hpp"
#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>
#include <vector>


using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<int> nums;
    std::int32_t expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums = loadVector(json.at("nums").as_array());
        expected = static_cast<std::int32_t>(json.at("expected").as_int64());
    }

    std::vector<int> const& getNums() const {
        return nums;
    }

    std::int32_t getExpected() const {
        return expected;
    }

private:
    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for (auto &element: json_array) {
            result.push_back(static_cast<int>(element.get_int64()));
        }
        return result;
    }

};