#include <vector>

#include <gtest/gtest.h>

#include <min_domino_rotations_for_equal_row.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::domino_min_rotations;

class MinDominosRotationTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(MinDominosRotationTests, MinRotations2) {
    MinDominoRotationsForEqualRow solution;

    std::vector<int> tops{2,1,2,4,2,2};
    std::vector<int> bottoms{5,2,6,2,3,2};
    int expected = 2;

    auto min_rotations = solution.minDominoRotations(tops, bottoms);
    ASSERT_EQ(expected, min_rotations);
}

TEST_F(MinDominosRotationTests, MinRotationsImpossible) {
    MinDominoRotationsForEqualRow solution;

    std::vector<int> tops{3,5,1,2,3};
    std::vector<int> bottoms{3,6,3,3,4};
    int expected = -1;

    auto min_rotations = solution.minDominoRotations(tops, bottoms);
    ASSERT_EQ(expected, min_rotations);
}

TEST_F(MinDominosRotationTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "min_domino_rotations_for_equal_row_1007";

    BaseLoader loader;
    MinDominoRotationsForEqualRow solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto tops = tc.getTops();
        auto bottoms = tc.getBottoms();
        auto actual = solution.minDominoRotations(tops, bottoms);
        auto expected = tc.getExpected();
        ASSERT_EQ(expected, actual);
    }
}