#pragma once

#include "res/ds_resource_utils.hpp"

#include "loader/base_loader.hpp"
#include "loader/bst/load_bst.hpp"

#include <boost/json.hpp>

#include <string>
#include <utility>
#include <vector>

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;
private:
    TreeNode *input;
    std::vector<std::vector<int>> expected;

public:
    explicit TestCase(std::filesystem::path const &file) {
        auto json = getJson(file);
        input = loadBst(json.at("input"));
        expected = loadMatrix(json.at("expected").as_array());
    }

    [[nodiscard]] std::vector<std::vector<int>> getExpected() const {
        return expected;
    }

    [[nodiscard]] TreeNode *getInput() {
        return input;
    }

private:
    static boost::json::value getJson(std::filesystem::path const &file) {
        BaseLoader loader;
        auto json_str = loader.load_file(file);
        return boost::json::parse(json_str);
    }

    static TreeNode *loadBst(boost::json::value &json) {
        auto bstInput = json.as_string().c_str();
        return loadBst(bstInput);
    }

public:
    static TreeNode *loadBst(std::string const &bstInput) {
        LoadBst bst_loader;
        return bst_loader.load_bst(bstInput);
    }

    static std::vector<int> loadVector(boost::json::array jsonVector) {
        std::vector<int> intVector;

        std::for_each(std::begin(jsonVector),std::end(jsonVector),
                      [&intVector](auto &value) { intVector.push_back(value.as_int64()); });

        return intVector;
    }

    static Matrix<int> loadMatrix(boost::json::array jsonMatrix) {
        Matrix<int> matrix;

        std::for_each(std::begin(jsonMatrix), std::end(jsonMatrix),
                      [&matrix](auto &v) { matrix.push_back(loadVector(v.as_array())); }
        );

        return matrix;
    }
};
