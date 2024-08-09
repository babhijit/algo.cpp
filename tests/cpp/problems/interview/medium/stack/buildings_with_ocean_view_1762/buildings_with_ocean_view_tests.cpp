#include <gtest/gtest.h>

#include "test_case.hpp"
#include <ocean_view_buildings.hpp>

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include "loader/test_case_loader.hpp"

using namespace algo::interview::medium::stack::ocean_view_buildings;

class OceanViewBuildingsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

    static void runTest(std::vector<int> heights, std::vector<int> expected) {
        OceanViewBuildings solution;
        auto actual = solution.findBuildings(heights);
        ASSERT_EQ(actual, expected);
    }
};


TEST_F(OceanViewBuildingsTests, TestCase1) {
    runTest({4, 2, 3, 1}, {0, 2, 3});
}

TEST_F(OceanViewBuildingsTests, TestCase2) {
    runTest({4, 3, 2, 1}, {0, 1, 2, 3});
}

TEST_F(OceanViewBuildingsTests, TestCase3) {
    runTest({1, 3, 2, 4}, {3});
}


TEST_F(OceanViewBuildingsTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("stack");
    auto usecase_dir = path / "buildings_with_ocean_view_1762";

    TestCaseLoader()(usecase_dir,
                     [](auto &fileName) {
                         TestCase tc(fileName);
                         runTest(tc.getHeights(), tc.getExpected());
                     });
}