#pragma once

#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    int num_;
    int expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        num_ = static_cast<int>(json.at("num").as_int64());
        expected_ = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] int const& getNum() const {
        return num_;
    }

    [[nodiscard]] int getExpected() const {
        return expected_;
    }
};