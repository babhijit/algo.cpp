#include <gtest/gtest.h>

#include "test_case.hpp"
#include <grp_anagrams.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::interview::medium::string::group_anagrams;

std::set<std::set<std::string>> toSet(Matrix<std::string> const& anagrams) {
    std::set<std::set<std::string>> result;

    for (auto& anagram: anagrams) {
        std::set<std::string> anagramSet(anagram.begin(), anagram.end());
        result.insert(anagramSet);
    }

    return result;
}

class GroupAnagramTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<std::string> strs, Matrix<std::string> expected) {
        GroupAnagram solution;
        auto actual = solution.groupAnagrams(strs);

        ASSERT_EQ(toSet(actual), toSet(expected));
    }
};


TEST_F(GroupAnagramTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("string");
    auto usecase_dir = path / "group_anagrams_49";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getStrs(), tc.getExpected());
                     });
}