#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"


using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    int input;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);
        input = json.at("input").as_int64();
        expected = json.at("expected").as_int64();
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] int getInput() const {
        return input;
    }

};


#endif //ALGO_CPP_TEST_CASE_HPP
