#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>
#include <vector>

#include <boost/json.hpp>

#include "loader/list/load_int_list.hpp"

using namespace algo::cpp::leetcode::ds;
using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::vector<int> nums;
    int limit;
    int expected;

public:
    explicit TestCase(boost::json::value&& json) {
        nums = loadVector(json.at("nums").as_array());
        limit = json.at("limit").as_int64();
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getLimit() const {
        return limit;
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<int> getNums() const {
        return nums;
    }


private:
    static std::vector<int> loadVector(boost::json::array json_array) {
        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(static_cast<int>(element.get_int64()));
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
