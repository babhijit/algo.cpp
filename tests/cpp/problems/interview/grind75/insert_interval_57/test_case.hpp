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
    IntMatrix intervals;
    std::vector<int> newIntervals;
    IntMatrix expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        intervals = loadMatrix(json.at("intervals").as_array());
        newIntervals = loadVector(json.at("newIntervals").as_array());
        expected = loadMatrix(json.at("expected").as_array());
    }

    [[nodiscard]] IntMatrix getExpected() const {
        return expected;
    }

    [[nodiscard]] IntMatrix getIntervals() const {
        return intervals;
    }

    [[nodiscard]] std::vector<int> getNewIntervals() const {
        return newIntervals;
    }

private:
    static inline std::vector<int> loadVector(boost::json::array json_array) {
        return LoadIntArray()(json_array);
    }

    static inline IntMatrix loadMatrix(boost::json::array json_array) {
        return LoadIntMatrix()(json_array);
    }
};
