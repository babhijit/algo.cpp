#include "test_case.hpp"

#include "sum_min_subarray.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/test_case_loader.hpp"

#include <vector>

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::stack::sum_subarray_mins;

namespace algo::problems::leetcode::stack::sum_subarray_mins::test {

    class SumOfSubarrayMinsTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(std::vector<int> arr, int expected) {
            SumOfSubarrayMins solution;
            auto actual = solution.sumSubarrayMins(arr);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getArr(), tc.getExpected());
        }
    };


    TEST_F(SumOfSubarrayMinsTests, LeetCodeSample1) {
        run_test_case({3, 1, 2, 4}, 17);
    }

    TEST_F(SumOfSubarrayMinsTests, LeetCodeSample2) {
        run_test_case({11, 81, 94, 43, 3}, 444);
    }


    TEST_F(SumOfSubarrayMinsTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("stack");
        auto usecase_dir = path / "sum_subarray_mins_907";

        TestCaseLoader()(usecase_dir,
                         [](auto &tc) { run_test_case(tc); });
    }

}