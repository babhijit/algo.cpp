#include <vector>

#include <gtest/gtest.h>

#include "climbing_stairs.hpp"

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::maths::climbing_stairs;

namespace algo::problems::leetcode::maths::climbing_stairs::test {

    class ClimbingStairsTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(int n, int expected) {
            ClimbingStairs solution;
            auto actual = solution.climbStairs(n);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getN(), tc.getExpected());
        }
    };


    TEST_F(ClimbingStairsTests, LeetCodeSample1) {
        run_test_case(2, 2);
    }

    TEST_F(ClimbingStairsTests, LeetCodeSample2) {
        run_test_case(3, 3);
    }


    TEST_F(ClimbingStairsTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("maths");
        auto usecase_dir = path / "climbing_stairs_70";

        std::for_each(std::filesystem::directory_iterator(usecase_dir),
                      std::filesystem::directory_iterator(),
                      [](auto& testCase) { run_test_case(testCase);});
    }

}