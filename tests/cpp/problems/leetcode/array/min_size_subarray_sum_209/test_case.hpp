#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"
#include "loader/arrays/load_int_array.hpp"

class TestCase {
private:
    std::vector<int> input;
    int target;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = load_vector(json.at("input").as_array());
        target = json.at("target").as_int64();
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] int getTarget() const {
        return target;
    }

    [[nodiscard]] std::vector<int> getInput() const {
        return input;
    }

private:
    static std::vector<int> load_vector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
