#pragma once

#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::string s_;
    int expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        s_ = json.at("s").as_string().c_str();
        expected_ = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] std::string const& getS() const {
        return s_;
    }

    [[nodiscard]] int getExpected() const {
        return expected_;
    }
};