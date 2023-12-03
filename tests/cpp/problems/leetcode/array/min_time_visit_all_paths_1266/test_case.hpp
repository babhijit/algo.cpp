#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<std::vector<int>> input;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = load_matrix(json.at("input").as_array());
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    std::vector<std::vector<int>>& getInput() {
        return input;
    }

private:
    static std::vector<std::vector<int>> load_matrix(boost::json::array json_array) {
        std::vector<std::vector<int>> result;
        for(auto &element: json_array) {
            std::vector<int> row = load_vector(element.as_array());
            result.emplace_back(std::move(row));
        }

        return result;
    }

    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
