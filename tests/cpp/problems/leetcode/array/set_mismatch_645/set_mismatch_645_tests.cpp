#include "test_case.hpp"

#include "set_mismatch.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/test_case_loader.hpp"

#include <vector>

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::array::set_mismatch;

namespace algo::problems::leetcode::array::set_mismatch::test {

    class SetMismatchTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(std::vector<int> num, std::vector<int> expected) {
            SetMismatch solution;
            auto actual = solution.findErrorNums(num);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getNum(), tc.getExpected());
        }
    };


    TEST_F(SetMismatchTests, LeetCodeSample1) {
        run_test_case({1, 2, 2, 4}, {2, 3});
    }

    TEST_F(SetMismatchTests, LeetCodeSample2) {
        run_test_case({1, 1}, {1, 2});
    }


    TEST_F(SetMismatchTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("array");
        auto usecase_dir = path / "set_mismatch_645";

        TestCaseLoader()(usecase_dir,
                         [](auto &tc) { run_test_case(tc); });
    }

}