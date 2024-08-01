#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> nums_;
    int expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums_ = LoadIntArray()(json.at("nums").as_array());
        expected_ = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] int getExpected() const {
        return expected_;
    }

    [[nodiscard]] std::vector<int> getNums() const {
        return nums_;
    }
};
