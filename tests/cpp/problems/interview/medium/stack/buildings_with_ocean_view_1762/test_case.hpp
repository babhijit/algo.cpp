#pragma once

#include "loader/arrays/load_int_array.hpp"
#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>
#include <vector>

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<int> heights_;
    std::vector<int> expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        heights_ = LoadIntArray()(json.at("heights").as_array());
        expected_ = LoadIntArray()(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<int> const& getHeights() const {
        return heights_;
    }

    [[nodiscard]] std::vector<int> getExpected() const {
        return expected_;
    }
};