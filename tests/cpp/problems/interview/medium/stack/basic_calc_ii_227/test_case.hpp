#pragma once

#include "loader/arrays/load_int_array.hpp"
#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <boost/json.hpp>

#include <cstdint>
#include <string>

using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::string s_;
    std::int32_t expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        s_ = json.at("s").as_string().c_str();
        expected_ = static_cast<std::int32_t>(json.at("expected").as_int64());
    }

    [[nodiscard]] std::string const& getS() const {
        return s_;
    }

    [[nodiscard]] std::int32_t getExpected() const {
        return expected_;
    }
};