#pragma once

#include "loader/base_loader.hpp"
#include "loader/arrays/load_t_matrix.hpp"

#include "utils/dstypedefs.hpp"

#include <boost/json.hpp>

#include <functional>
#include <string>
#include <vector>

using namespace algo::cpp::ds::utils;


class TestCase {
private:
    Matrix<char> grid_;
    int expected_;

    struct CharTransformer {
        char operator()(boost::json::value& v) const {
            std::string strValue = v.as_string().c_str();
            return strValue[0];
        }
    };

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        using namespace algo::cpp::ds::tests::utils;

        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        grid_ = LoadTMatrix<char, CharTransformer>()(json.at("grid").as_array());
        expected_ = static_cast<int>(json.at("expected").as_int64());
    }

    [[nodiscard]] int getExpected() const {
        return expected_;
    }

    [[nodiscard]] Matrix<char> getGrid() const {
        return grid_;
    }
};
