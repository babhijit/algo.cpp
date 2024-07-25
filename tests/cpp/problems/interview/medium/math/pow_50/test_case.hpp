#pragma once

#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    double x_;
    int n_;
    double expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        x_ = json.at("x").as_double();
        n_ = static_cast<std::int32_t>(json.at("n").as_int64());
        expected_ = json.at("expected").as_double();
    }

    [[nodiscard]] double const& getX() const {
        return x_;
    }

    [[nodiscard]] int const& getN() const {
        return n_;
    }

    [[nodiscard]] double getExpected() const {
        return expected_;
    }
};