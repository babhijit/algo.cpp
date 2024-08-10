#pragma once

#include <string>
#include <vector>

#include <utils/dstypedefs.hpp>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_str_matrix.hpp"

using namespace algo::cpp::ds::utils;

class TestCase {
private:
    Matrix<char> board_;
    std::string word_;
    bool expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        auto board = LoadStrMatrix()(json.at("board").as_array());

        auto convertFromStrMatrix2CharMatrix = [](Matrix<std::string> strMatrix) -> Matrix<char> {
            Matrix<char> charMatrix;
            for (auto& strRow: strMatrix) {
                std::vector<char> charRow;
                charRow.reserve(strRow.size());
                for (auto& str: strRow) {
                    charRow.push_back(str[0]);
                }
                charMatrix.push_back(charRow);
            }
            return charMatrix;
        };
        board_ = convertFromStrMatrix2CharMatrix(std::move(board));
        word_ = json.at("word").as_string().c_str();
        expected_ = json.at("expected").as_bool();
    }

    [[nodiscard]] bool getExpected() const {
        return expected_;
    }

    [[nodiscard]] Matrix<char> getBoard() const {
        return board_;
    }

    [[nodiscard]] std::string getWord() const {
        return word_;
    }
};
