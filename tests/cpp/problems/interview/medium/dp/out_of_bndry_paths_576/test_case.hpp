#pragma once

#include "loader/json_loader.hpp"

#include <boost/json.hpp>

#include <filesystem>


namespace algo::interview::medium::dp::out_of_boundary_paths::test {

    class TestCase {
    private:
        int m, n, maxMove, startRow, startColumn;
        int expected;

    public:
        explicit TestCase(boost::json::value &&json) :
                m(json.at("m").as_int64()),
                n(json.at("n").as_int64()),
                maxMove(json.at("maxMove").as_int64()),
                startRow(json.at("startRow").as_int64()),
                startColumn(json.at("startColumn").as_int64()),
                expected(json.at("expected").as_int64()) {
        }

        explicit TestCase(const std::filesystem::path &file_name) :
                TestCase(JsonLoader()(file_name)) {
        }


        [[nodiscard]] int getM() const {
            return m;
        }

        [[nodiscard]] int getN() const {
            return n;
        }

        [[nodiscard]] int getMaxMove() const {
            return maxMove;
        }

        [[nodiscard]] int getStartRow() const {
            return startRow;
        }

        [[nodiscard]] int getStartColumn() const {
            return startColumn;
        }

        [[nodiscard]] int getExpected() const {
            return expected;
        }
    };

} // algo::problems::leetcode::array::house_robber::test
