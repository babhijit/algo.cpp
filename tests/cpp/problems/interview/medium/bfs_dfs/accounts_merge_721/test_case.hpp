#pragma once

#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_t_matrix.hpp"

#include "utils/dstypedefs.hpp"

#include <functional>
#include <string>

using namespace algo::cpp::ds::utils;

class TestCase {
private:
    Matrix<std::string> accounts_;
    Matrix<std::string> expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        using Transformer = std::function<std::string(boost::json::value &)>;
        Transformer transformer = [](boost::json::value &jv) {
            return std::string(jv.as_string());
        };
        LoadTMatrix<std::string, Transformer> matrixLoader(std::move(transformer));

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        accounts_ = matrixLoader(json.at("accounts").as_array());
        expected_ = matrixLoader(json.at("expected").as_array());
    }

    [[nodiscard]] Matrix<std::string> getExpected() const {
        return expected_;
    }

    [[nodiscard]] Matrix<std::string> getAccounts() const {
        return accounts_;
    }
};
