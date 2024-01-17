#include <vector>

#include <gtest/gtest.h>

#include "uniq_occ.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::hashtable::uniq_occurrences;

namespace algo::problems::leetcode::hastable::uniq_occurences::test {

    class UniqueOccurrencesTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}
    };


    TEST_F(UniqueOccurrencesTests, LeetCodeSample1) {
        UniqueOccurrences solution;

        std::vector<int> nums{1,2,2,1,1,3};
        bool expected = true;

        auto actual = solution.uniqueOccurrences(nums);
        ASSERT_EQ(expected, actual);
    }

    TEST_F(UniqueOccurrencesTests, LeetCodeSample2) {
        UniqueOccurrences solution;

        std::vector<int> nums{1, 2};
        bool expected = false;

        auto actual = solution.uniqueOccurrences(nums);
        ASSERT_EQ(expected, actual);
    }

    TEST_F(UniqueOccurrencesTests, LeetCodeSample3) {
        UniqueOccurrences solution;

        std::vector<int> nums{-3,0,1,-3,1,1,1,-3,10,0};
        bool expected = true;

        auto actual = solution.uniqueOccurrences(nums);
        ASSERT_EQ(expected, actual);
    }


    TEST_F(UniqueOccurrencesTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("hashtable");
        auto usecase_dir = path / "uniq_occ_1207";

        BaseLoader loader;
        UniqueOccurrences solution;
        for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
            auto json_str = loader.load_file(testcase);
            TestCase tc(boost::json::parse(json_str));

            auto nums = tc.getInput();
            auto actual = solution.uniqueOccurrences(nums);
            auto expected = tc.getExpected();
            ASSERT_EQ(expected, actual);
        }
    }

}