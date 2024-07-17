#pragma once
#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"
#include "loader/arrays/load_int_matrix.hpp"

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    IntMatrix mat;
    IntMatrix expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        mat = loadMatrix(json.at("mat").as_array());
        expected = loadMatrix(json.at("expected").as_array());
    }

    [[nodiscard]] IntMatrix getExpected() const {
        return expected;
    }

    [[nodiscard]] IntMatrix getMat() const {
        return mat;
    }

private:
    static inline IntMatrix loadMatrix(boost::json::array json_array) {
        return LoadIntMatrix()(json_array);
    }
};
