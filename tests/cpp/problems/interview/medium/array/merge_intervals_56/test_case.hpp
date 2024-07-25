#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_matrix.hpp"

class TestCase {
private:
    std::vector<std::vector<int>> intervals_;
    std::vector<std::vector<int>> expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        intervals_ = load_matrix(json.at("intervals").as_array());
        expected_ = load_matrix(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<std::vector<int>> getExpected() const {
        return expected_;
    }


    [[nodiscard]] std::vector<std::vector<int>> getIntervals() const {
        return intervals_;
    }

private:

    static std::vector<std::vector<int>> load_matrix(boost::json::array json_array) {
        using namespace algo::cpp::ds::tests::utils;
        return LoadIntMatrix()(json_array);
    }
};

