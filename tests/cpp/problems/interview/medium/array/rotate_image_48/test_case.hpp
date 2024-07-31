#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_matrix.hpp"

#include <utils/dstypedefs.hpp>

using namespace algo::cpp::ds::utils;

class TestCase {
private:
    Matrix<int> matrix_;
    Matrix<int> expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        matrix_ = LoadIntMatrix()(json.at("matrix").as_array());
        expected_ = LoadIntMatrix()(json.at("expected").as_array());
    }

    [[nodiscard]] Matrix<int> getExpected() const {
        return expected_;
    }

    [[nodiscard]] Matrix<int> getMatrix() const {
        return matrix_;
    }
};
