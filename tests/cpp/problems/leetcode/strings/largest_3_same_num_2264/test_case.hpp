#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"


using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::string input;
    std::string expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = json.at("input").as_string();
        expected = json.at("expected").as_string();
    }

    [[nodiscard]] std::string getExpected() const {
        return expected;
    }

    [[nodiscard]] std::string getInput() const {
        return input;
    }

};


#endif //ALGO_CPP_TEST_CASE_HPP
