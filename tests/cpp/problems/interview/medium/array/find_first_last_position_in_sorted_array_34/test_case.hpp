#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<int> nums;
    int target;
    std::vector<int> expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);

        LoadIntArray intArrayLoader;
        nums = intArrayLoader(json.at("nums").as_array());
        target = static_cast<int>(json.at("target").as_int64());
        expected = intArrayLoader(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<int> getExpected() const {
        return expected;
    }


    [[nodiscard]] std::vector<int> getNums() const {
        return nums;
    }

    [[nodiscard]] int getTarget() const {
        return target;
    }
};
