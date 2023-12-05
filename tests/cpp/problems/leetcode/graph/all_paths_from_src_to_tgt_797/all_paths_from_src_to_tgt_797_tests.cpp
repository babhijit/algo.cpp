#include <vector>

#include <gtest/gtest.h>

#include <all_paths_from_src_to_tgt.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::graph::all_paths_from_src_to_tgt;

class AllPathsFromSourceToTargetTests : public ::testing::Test {
protected:
    using Graph = AllPathsFromSourceToTarget::Graph;

    void SetUp() override {}

    void TearDown() override {}

public:
    void run_tests(AllPathsFromSourceToTarget::Graph &input,
                   AllPathsFromSourceToTarget::Graph &expected) {
        auto exec_tc = [&] {
            AllPathsFromSourceToTarget solution;
            auto actual = solution.allPathsSourceTarget(input);

            ASSERT_EQ(expected, actual);
        };

        ASSERT_NO_THROW(exec_tc());
    }
};


TEST_F(AllPathsFromSourceToTargetTests, MinRotations2) {
    Graph input{{1, 2},
                {3},
                {3},
                {}};
    Graph expected{{0, 1, 3},
                   {0, 2, 3}};

    run_tests(input, expected);
}


TEST_F(AllPathsFromSourceToTargetTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("graph");
    auto usecase_dir = path / "all_paths_from_src_to_tgt_797";

    BaseLoader loader;
    for (const auto &testcase: std::filesystem::directory_iterator(usecase_dir)) {
        TestCase tc(testcase);

        auto input = tc.getInput();
        auto expected = tc.getExpected();
        run_tests(input, expected);
    }
}