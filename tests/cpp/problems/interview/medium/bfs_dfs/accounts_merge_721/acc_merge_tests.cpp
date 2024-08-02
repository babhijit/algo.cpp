
#include "test_case.hpp"

#include "acc_merge.hpp"

#include "res/ds_resource_utils.hpp"
#include "iview_file_utils.hpp"
#include <gtest/gtest.h>


using namespace algo::interview::bfs_dfs::acc_merge;

namespace {
    using SortedAccount = std::map<std::string, std::set<std::string>>;

    SortedAccount createAccount(Matrix<std::string> const& accounts) {
        SortedAccount sa;
        for (auto& account: accounts) {
            auto& name = account[0];
            auto& emails = sa[name];
            emails.insert(std::next(account.begin()), account.end());
        }
        return sa;
    }

    bool isEqual(Matrix<std::string> const& a, Matrix<std::string> const& b) {
        SortedAccount A = createAccount(a);
        SortedAccount B = createAccount(b);
        return A == B;
    }
}

class AccountsMergeTests : public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}

protected:
    static void runTest(Matrix<std::string> accounts, Matrix<std::string> expected) {
        AcctMerge solution;
        auto result = solution.accountsMerge(accounts);
        ASSERT_TRUE(isEqual(expected, result));
    }

    static void runTestCase(const std::filesystem::path &testcase) {
        TestCase tc(testcase);

        auto accounts = tc.getAccounts();
        auto expected = tc.getExpected();

        runTest(std::move(accounts), std::move(expected));
    }
};

TEST_F(AccountsMergeTests, RunTestsFromResource) {
    using namespace algo::cpp::ds::tests::utils::interview;
    auto path = get_test_ds_dir("bfs_dfs");
    auto usecase_dir = path / "accounts_merge_721";

    std::for_each(std::filesystem::directory_iterator(usecase_dir),
                  std::filesystem::directory_iterator(),
                  [](const auto &testcase) {
                      runTestCase(testcase);
                  });
}
