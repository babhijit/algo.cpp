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
    int n_;
    std::string expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        n_ = static_cast<std::int32_t>(json.at("n").as_int64());
        expected_ = json.at("expected").as_string().c_str();
    }

    [[nodiscard]] int const& getN() const {
        return n_;
    }

    [[nodiscard]] std::string getExpected() const {
        return expected_;
    }
};