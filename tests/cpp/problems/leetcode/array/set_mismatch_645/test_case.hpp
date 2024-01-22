#pragma once

#include "loader/json_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

#include <boost/json.hpp>

#include <filesystem>

using namespace algo::cpp::ds::tests::utils;

namespace algo::problems::leetcode::array::set_mismatch::test {

    class TestCase {
    private:
        std::vector<int> num;
        std::vector<int> expected;

    public:
        explicit TestCase(boost::json::value &&json) :
                num(LoadIntArray()(json.at("num").as_array())),
                expected(LoadIntArray()(json.at("expected").as_array())) {
        }

        explicit TestCase(const std::filesystem::path &file_name) :
                TestCase(JsonLoader()(file_name)) {
        }

        [[nodiscard]] std::vector<int> getNum() const {
            return num;
        }

        [[nodiscard]] std::vector<int> getExpected() const {
            return expected;
        }
    };

} // algo::problems::leetcode::array::house_robber::test
