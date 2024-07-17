#pragma once
#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> nums;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums = loadVector(json.at("nums").as_array());
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }


    [[nodiscard]] std::vector<int> getNums() const {
        return nums;
    }

private:
    static inline std::vector<int> loadVector(boost::json::array json_array) {
        using namespace algo::cpp::ds::tests::utils;
        return LoadIntArray()(json_array);
    }
};
