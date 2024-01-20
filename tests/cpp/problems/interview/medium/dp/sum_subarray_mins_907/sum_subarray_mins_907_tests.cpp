#include "test_case.hpp"

#include "dp_sum_min_subarray.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

#include <vector>

#include <gtest/gtest.h>


using namespace algo::interview::medium::dp::sum_subarray_mins;

namespace algo::interview::medium::dp::sum_subarray_mins::test {

    class DpSumOfSubarrayMinsTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(std::vector<int> arr, int expected) {
            DpSumOfSubarrayMins solution;
            auto actual = solution.sumSubarrayMins(arr);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getArr(), tc.getExpected());
        }
    };


    TEST_F(DpSumOfSubarrayMinsTests, LeetCodeSample1) {
        run_test_case({3, 1, 2, 4}, 17);
    }

    TEST_F(DpSumOfSubarrayMinsTests, LeetCodeSample2) {
        run_test_case({11, 81, 94, 43, 3}, 444);
    }


    TEST_F(DpSumOfSubarrayMinsTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::interview;
        auto path = get_test_ds_dir("dp");
        auto usecase_dir = path / "sum_subarray_mins_907";

        TestCaseLoader()(usecase_dir,
                         [](auto &tc) { run_test_case(tc); });
    }

}