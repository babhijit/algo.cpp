#include <vector>

#include <gtest/gtest.h>

#include <grumpy_bookstore_owner.hpp>

#include "res/ds_resource_utils.hpp"
#include "lc_file_utils.hpp"
#include "loader/base_loader.hpp"

#include "test_case.hpp"


using namespace algo::problems::leetcode::array::grumpy_bookstore_owner_1052;

class GrumpyBookstoreOwnerTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};


TEST_F(GrumpyBookstoreOwnerTests, Sample1) {
    GrumpyBookstoreOwner solution;

    std::vector<int> customers{1,0,1,2,1,1,7,5};
    std::vector<int> grumpy{0,1,0,1,0,1,0,1};
    int minutes = 3;
    int expected = 16;

    auto result = solution.maxSatisfied(customers, grumpy, minutes);
    ASSERT_EQ(result, expected);
}

TEST_F(GrumpyBookstoreOwnerTests, Sample2) {
    GrumpyBookstoreOwner solution;

    std::vector<int> customers{1};
    std::vector<int> grumpy{0};
    int minutes = 1;
    int expected = 1;

    auto result = solution.maxSatisfied(customers, grumpy, minutes);
    ASSERT_EQ(result, expected);
}


TEST_F(GrumpyBookstoreOwnerTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::leetcode;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "grumpy_bookstore_owner_1052";

    BaseLoader loader;
    GrumpyBookstoreOwner solution;
    for (const auto& testcase: std::filesystem::directory_iterator(usecase_dir)) {
        auto json_str = loader.load_file(testcase);
        TestCase tc(boost::json::parse(json_str));

        auto customers = tc.getCustomers();
        auto grumpy = tc.getGrumpy();
        auto minutes = tc.getMinutes();
        auto actual = solution.maxSatisfied(customers, grumpy, minutes);
        auto expected = tc.getExpected();
        ASSERT_EQ(expected, actual);
    }
}