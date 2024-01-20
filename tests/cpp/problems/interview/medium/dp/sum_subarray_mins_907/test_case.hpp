#pragma once

#include "loader/json_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

#include <boost/json.hpp>

#include <filesystem>

using namespace algo::cpp::ds::tests::utils;

namespace algo::interview::medium::dp::sum_subarray_mins::test {

    class TestCase {
    private:
        std::vector<int> arr;
        int expected;

    public:
        explicit TestCase(boost::json::value &&json) :
                arr(LoadIntArray()(json.at("arr").as_array())),
                expected(json.at("expected").as_int64()) {
        }

        explicit TestCase(const std::filesystem::path &file_name) :
                TestCase(JsonLoader()(file_name)) {
        }

        [[nodiscard]] std::vector<int> getArr() const {
            return arr;
        }

        [[nodiscard]] int getExpected() const {
            return expected;
        }
    };

} // algo::problems::leetcode::array::sum_subarray_mins::test
