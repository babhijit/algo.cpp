
#include "test_case.hpp"

#include "friends.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>

#include <vector>


using namespace algo::interview::medium::array::friends;

class FriendRequestsTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(std::vector<int> ages, int expected) {
        Friends solution;
        auto result = solution.numFriendsRequests(ages);
        ASSERT_EQ(expected, result);
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto ages = tc.getAges();
        auto expected = tc.getExpected();

        runTest(std::move(ages), expected);
    }
};


TEST_F(FriendRequestsTests, LeetCodeSample1) {
    runTest({16,16}, 2);
}

TEST_F(FriendRequestsTests, LeetCodeSample2) {
    runTest({16,17,18}, 2);
}

TEST_F(FriendRequestsTests, LeetCodeSample3) {
    runTest({20,30,100,110,120}, 3);
}


TEST_F(FriendRequestsTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("array");
    auto usecase_dir = path / "friends_of_appropriate_ages_825";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
