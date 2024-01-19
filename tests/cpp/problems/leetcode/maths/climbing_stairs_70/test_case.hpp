#pragma once

#include "loader/json_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>

namespace algo::problems::leetcode::maths::climbing_stairs::test {

    class TestCase {
        inline static JsonLoader jsonLoader;

    private:
        int n;
        int expected;
    public:
        explicit TestCase(boost::json::value &&json) {
            n = json.at("n").as_int64();
            expected = json.at("expected").as_int64();
        }

        explicit TestCase(const std::filesystem::path &file_name) :
                TestCase(jsonLoader.loadJson(file_name)) {
        }

        [[nodiscard]] int getN() const {
            return n;
        }

        [[nodiscard]] int getExpected() const {
            return expected;
        }
    };

} // algo::problems::leetcode::hastable::climbing_stairs::test

