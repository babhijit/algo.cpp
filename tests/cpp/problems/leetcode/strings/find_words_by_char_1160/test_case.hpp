#ifndef ALGO_CPP_TEST_CASE_HPP
#define ALGO_CPP_TEST_CASE_HPP


#include <boost/json.hpp>

#include "loader/base_loader.hpp"

#include <string>
#include <utility>
#include <vector>


class TestCase {
private:
    std::vector<std::string> words;
    std::string chars;
    int64_t expected;

public:
    explicit TestCase(const std::filesystem::path &testcase) {
        BaseLoader loader;
        auto json_str = loader.load_file(testcase);

        auto parsed_data = boost::json::parse(json_str);
        const boost::json::object& json_object = parsed_data.as_object();

        for(const auto& [key, value] : json_object) {

            if (key == "words") {
                assert(value.is_array() && "Expected array");
                words = getStrings(value.as_array());
            } else if (key == "chars") {
                assert(value.is_string() && "Expected string");
                chars = value.as_string().c_str();
            } else if (key == "expected") {
                assert(value.is_int64() && "Expected int64");
                expected = value.as_int64();
            } else {
                assert(false && "Unknown key");
            }
        }
    }

    [[nodiscard]] int64_t getExpected() const {
        return expected;
    }

    [[nodiscard]] std::vector<std::string> getWords() const {
        return words;
    }

    [[nodiscard]] std::string getChars() const {
        return chars;
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
