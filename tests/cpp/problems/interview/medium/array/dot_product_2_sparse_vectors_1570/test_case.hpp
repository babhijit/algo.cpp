#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> nums1_;
    std::vector<int> nums2_;
    int expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums1_ = LoadIntArray()(json.at("nums1").as_array());
        nums2_ = LoadIntArray()(json.at("nums2").as_array());
        expected_ = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] int getExpected() const {
        return expected_;
    }

    [[nodiscard]] std::vector<int> getNums1() const {
        return nums1_;
    }

    [[nodiscard]] std::vector<int> getNums2() const {
        return nums2_;
    }
};
