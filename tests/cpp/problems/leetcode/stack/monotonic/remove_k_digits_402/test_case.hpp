#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <string>
#include <utility>

#include <boost/json.hpp>

#include "loader/base_loader.hpp"


using namespace algo::cpp::ds::tests::utils;

class TestCase {
private:
    std::string num;
    int k;
    std::string expected;

public:
    explicit TestCase(std::string num,
             int k,
             std::string expected) : num(std::move(num)),
                                     k(k),
                                     expected(std::move(expected)) {}

    TestCase(TestCase &&tc) : num(std::move(tc.num)),
                              k(tc.k),
                              expected(std::move(tc.expected)) {}

    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);
        auto json = boost::json::parse(json_str);

        num = json.at("num").as_string();
        k = static_cast<int>(json.at("k").as_int64());
        expected = json.at("expected").as_string();
    }


    [[nodiscard]] std::string getExpected() const {
        return expected;
    }

    [[nodiscard]] std::string getNum() const {
        return num;
    }

    [[nodiscard]] int getK() const {
        return k;
    }
};


#endif //ALGO_CPP_TEST_CASE_HPP
