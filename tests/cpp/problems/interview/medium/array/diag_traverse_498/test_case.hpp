#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"
#include "loader/arrays/load_int_matrix.hpp"

class TestCase {
private:
    std::vector<int> expected;
    std::vector<std::vector<int>> nums;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        nums = LoadIntMatrix()(json.at("nums").as_array());
        expected = LoadIntArray()(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<int> getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<std::vector<int>> getNums() const {
        return nums;
    }
};
