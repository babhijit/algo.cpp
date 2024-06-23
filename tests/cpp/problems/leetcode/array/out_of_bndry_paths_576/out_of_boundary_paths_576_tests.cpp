#include "test_case.hpp"

#include "out_of_boundary_paths.hpp"

#include "res/ds_resource_utils.hpp"
#include "loader/test_case_loader.hpp"
#include "lc_file_utils.hpp"

#include <vector>

#include <gtest/gtest.h>


using namespace algo::problems::leetcode::array::out_of_boundary_paths;

namespace algo::problems::leetcode::array::out_of_boundary_paths::test {

    class OutOfBoundaryPathsTests : public ::testing::Test {
    protected:
        void SetUp() override {}

        void TearDown() override {}

    protected:
        static void run_test_case(int m, int n, int maxMove, int startRow, int startColumn,
                                  int expected) {
            OutOfBoundaryPaths solution;
            auto actual = solution.findPaths(m, n, maxMove, startRow, startColumn);
            ASSERT_EQ(expected, actual);
        }

        static void run_test_case(const std::filesystem::path &fileName) {
            TestCase tc(fileName);
            run_test_case(tc.getM(), tc.getN(), tc.getMaxMove(), tc.getStartRow(), tc.getStartColumn(),
                          tc.getExpected());
        }
    };


    TEST_F(OutOfBoundaryPathsTests, LeetCodeSample1) {
        run_test_case(2, 2, 2, 0, 0, 6);
    }

    TEST_F(OutOfBoundaryPathsTests, LeetCodeSample2) {
        run_test_case(1, 3, 3, 0, 1, 12);
    }

    TEST_F(OutOfBoundaryPathsTests, LeetCodeSample3) {
        run_test_case(36, 5, 50, 15, 3, 390153306);
    }


    TEST_F(OutOfBoundaryPathsTests, RunTestsFromResource) {
        using namespace algo::cpp::ds::tests::utils::leetcode;
        auto path = get_test_ds_dir("array");
        auto usecase_dir = path / "out_of_bndry_paths_576";

        TestCaseLoader()(usecase_dir,
                         [](auto &tc) { run_test_case(tc); });
    }

}