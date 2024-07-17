
#include "test_case.hpp"

#include "update_matrix.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::grind75::update_matrix_01;
using namespace algo::cpp::ds::tests::utils;

class UpdateMatrix01Tests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(IntMatrix mat, IntMatrix expected) {
        UpdateMatrix solution;
        auto result = solution.updateMatrix(mat);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto mat = tc.getMat();
        auto expected = tc.getExpected();

        runTest(std::move(mat),
                std::move(expected));
    }
};


TEST_F(UpdateMatrix01Tests, LeetCodeSample1) {
    runTest({{0,0,0}, {0,1,0},{1,1,1}},
            {{0, 0 ,0}, {0, 1, 0}, {1, 2, 1}});
}

TEST_F(UpdateMatrix01Tests, LeetCodeSample2) {
    runTest({{0,0,0}, {0,1,0},{0, 0, 0}},
            {{0, 0 ,0}, {0, 1, 0}, {0, 0, 0}});
}

TEST_F(UpdateMatrix01Tests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "o1_matrix_542";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
