#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"
#include "loader/arrays/load_int_matrix.hpp"

using Matrix = std::vector<std::vector<int>>;

class TestCase {
private:
    Matrix points_;
    int k_;
    Matrix expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        points_ = LoadIntMatrix()(json.at("points").as_array());
        k_ = static_cast<int>(json.at("k").as_int64());
        expected_ = LoadIntMatrix()(json.at("expected").as_array());
    }

    [[nodiscard]] Matrix getExpected() const {
        return expected_;
    }

    [[nodiscard]] Matrix getPoints() const {
        return points_;
    }

    [[nodiscard]] int getK() const {
        return k_;
    }
};
