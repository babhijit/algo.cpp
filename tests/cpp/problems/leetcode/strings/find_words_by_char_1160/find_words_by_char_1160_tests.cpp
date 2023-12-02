#include "test_case.hpp"

#include "res/ds_resource_utils.hpp"
#include "../../utils/include/file_utils.hpp"

#include "find_words_by_char.hpp"

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::strings::find_words_by_char;
using namespace algo::cpp::ds::tests::utils;

class FindWordsByCharTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

public:
    void run_test(std::vector<std::string> words, std::string chars, int expected) {
        FindWordsByChar solution;
        auto actual = solution.countCharacters(words, chars);
        ASSERT_EQ(expected, actual);
    }
};


TEST_F(FindWordsByCharTests, LeetCodeSample1) {
    run_test({"cat","bt","hat","tree"}, "atach", 6);
}

TEST_F(FindWordsByCharTests, LeetCodeSample2) {
    run_test({"hello","world","leetcode"}, "welldonehoneyr", 10);
}


TEST_F(FindWordsByCharTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("strings");
    auto usecase_dir = path / "find_words_by_char_1160";

    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto words = tc.getWords();
        auto chars = tc.getChars();
        auto expected = tc.getExpected();
        run_test(words, chars, expected);
    }
}