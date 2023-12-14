#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <vector>

#include <boost/json.hpp>


#include "loader/arrays/load_int_array.hpp"

class TestCase {
public:
    using Matrix = std::vector<std::vector<int>>;
private:
    std::vector<std::string> input;
    Matrix expected;

public:
    TestCase(boost::json::value&& json) {
        input = load_str_vector(json.at("root").as_array());
        expected = load_matrix(json.at("output").as_array());
    }

    Matrix getExpected() const {
        return expected;
    }

    std::vector<std::string> getInput() {
        return input;
    }


private:
    std::vector<int> loadVector(boost::json::array json_array) {

        std::vector<int> result;
        for(auto &element: json_array) {
            result.push_back(element.get_int64());
        }

        return result;
    }

    Matrix load_matrix(boost::json::array json_matrix) {
        Matrix result;
        for(auto &element: json_matrix) {
            auto row = loadVector(element.as_array());
            result.push_back(row);
        }

        return result;
    }

    std::vector<std::string> load_str_vector(boost::json::array json_array) {

        std::vector<std::string> result;
        for(auto &element: json_array) {
            result.push_back(element.get_string().c_str());
        }

        return result;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
