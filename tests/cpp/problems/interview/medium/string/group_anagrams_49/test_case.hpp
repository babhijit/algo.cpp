#pragma once

#include "loader/arrays/load_t_array.hpp"
#include "loader/arrays/load_t_matrix.hpp"
#include "loader/base_loader.hpp"

#include "lc_file_utils.hpp"

#include <utils/dstypedefs.hpp>

#include <boost/json.hpp>

#include <cstdint>
#include <string>
#include <vector>

using namespace algo::cpp::ds::utils;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<std::string> strs_;
    Matrix<std::string> expected_;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using Transformer = std::function<std::string(boost::json::value&)>;
        Transformer transformer = [](boost::json::value& jsonStr) {
            return std::string(jsonStr.as_string().c_str());
        };

        LoadTArray<std::string, Transformer> strVecLoader(transformer);
        LoadTMatrix<std::string, Transformer> strMatrixLoader(transformer);

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        strs_ = strVecLoader(json.at("strs").as_array());
        expected_ = strMatrixLoader(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<std::string> const& getStrs() const {
        return strs_;
    }

    [[nodiscard]] Matrix<std::string> getExpected() const {
        return expected_;
    }
};