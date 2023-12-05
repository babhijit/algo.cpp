#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

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