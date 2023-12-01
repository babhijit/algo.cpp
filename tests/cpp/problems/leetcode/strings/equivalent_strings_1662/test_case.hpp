#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <boost/json.hpp>

#include "loader/base_loader.hpp"

#include <string>
#include <utility>
#include <vector>


class TestCase {
private:
    std::vector<std::string> word1;
    std::vector<std::string> word2;
    int expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);

        auto parsed_data = boost::json::parse(json_str);
        const boost::json::object& json_object = parsed_data.as_object();

        for(const auto& [key, value] : json_object) {

            if (key == "word1") {
                assert(value.is_array() && "Expected array");
                word1 = getStrings(value.as_array());
            } else if (key == "word2") {
                assert(value.is_array() && "Expected array");
                word2 = getStrings(value.as_array());
            } else if (key == "expected") {
                assert(value.is_bool() && "Expected bool");
                expected = value.as_bool();
            } else {
                assert(false && "Unknown key");
            }
        }
    }

    [[nodiscard]] int getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<std::string> getWord1() const {
        return word1;
    }

    [[nodiscard]] std::vector<std::string> getWord2() const {
        return word2;
    }

private:
    static std::vector<std::string> getStrings(const boost::json::array& arr) {
        std::vector<std::string> result;
        for (const auto& item : arr) {
            assert(item.is_string() && "Expected string");
            result.emplace_back(item.as_string().c_str());
        }
        return result;
    }

};


#endif //ALGO_CPP_TEST_CASE_HPP
