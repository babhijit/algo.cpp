
#include "test_case.hpp"

#include "word_search.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <set>


using namespace algo::interview::medium::bt::word_search;

class WordSearchTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(Matrix<char> board, std::string word, bool expected) {
        WordSearch solution;
        auto result = solution.exist(board, word);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto board = tc.getBoard();
        auto word = tc.getWord();
        auto expected = tc.getExpected();

        runTest(std::move(board), std::move(word), expected);
    }
};

TEST_F(WordSearchTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("bt");
    auto usecase_dir = path / "word_search_79";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
