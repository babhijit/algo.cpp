#include "test_case.hpp"

#include "house_robber.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/test_case_loader.hpp"

#include <vector>

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::array::house_robber;

namespace algo::problems::leetcode::array::house_robber::test {

    class HouseRobberTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(std::vector<int> arr, int expected) {
            HouseRobber solution;
            auto actual = solution.rob(arr);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getArr(), tc.getExpected());
        }
    };


    TEST_F(HouseRobberTests, LeetCodeSample1) {
        run_test_case({1, 2, 3, 1}, 4);
    }

    TEST_F(HouseRobberTests, LeetCodeSample2) {
        run_test_case({2, 7, 9, 3, 1}, 12);
    }


    TEST_F(HouseRobberTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("array");
        auto usecase_dir = path / "house_robber_198";

        TestCaseLoader()(usecase_dir,
                         [](auto &tc) { run_test_case(tc); });
    }

}