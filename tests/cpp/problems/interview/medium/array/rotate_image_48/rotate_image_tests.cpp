
#include "test_case.hpp"

#include "rotate_image.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <iostream>

using namespace algo::interview::medium::array::rotate_image;

class RotateImageTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(Matrix<int>&& points, Matrix<int>&& expected) {
        RotateImage solution;
        solution.rotate(points);
        ASSERT_EQ(expected, points);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        std::cout << "Running testcase " << testcase.c_str() << std::endl;
        TestCase tc(testcase);
        runTest(tc.getMatrix(), tc.getExpected());
    }
};


TEST_F(RotateImageTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "rotate_image_48";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
