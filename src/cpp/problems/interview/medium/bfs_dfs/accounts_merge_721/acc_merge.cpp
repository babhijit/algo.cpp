#include "acc_merge.hpp"

#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/**
 * Time Complexity: O(MN log(MN))
 * Space Complexity: O(MN)
 */

namespace algo::interview::bfs_dfs::acc_merge {

    class Graph {
    public:
        [[nodiscard]] std::vector<std::string> const& adj(std::string const& v) const {
            return adjList_.at(v);
        }

        void add(std::string const& v, std::string const& w) {
            adjList_[v].push_back(w);
            adjList_[w].push_back(v);
            ++E_;
        }

        [[nodiscard]] std::size_t V() const {
            return adjList_.size();
        }

        [[nodiscard]] std::size_t E() const {
            return E_;
        }

    private:
        int E_{};
        std::unordered_map<std::string, std::vector<std::string>> adjList_;
    };

    class CC {
    public:
        explicit CC(Graph const& G, Matrix<std::string> const& accounts) {
            for (auto const& account: accounts) {
                auto& name = account[0];
                auto& firstEmail = account[1];

                if (not isVisited(firstEmail)) {
                    std::vector<std::string> mergedAccount;
                    mergedAccount.push_back(name);
                    dfs(G, firstEmail, mergedAccount);

                    std::sort(std::next(mergedAccount.begin()), mergedAccount.end());
                    mergedAccounts_.push_back(mergedAccount);
                }
            }
        }

        [[nodiscard]] Matrix<std::string> mergedAccounts() {
            return mergedAccounts_;
        }

    private:
        void dfs(Graph const& G, std::string const& email, std::vector<std::string>& account) {
            visited_.insert(email);
            account.push_back(email);

            for (auto& nextEmail: G.adj(email)) {
                if (not isVisited(nextEmail)) {
                    dfs(G, nextEmail, account);
                }
            }
        }

        [[nodiscard]] bool isVisited(std::string const& email) const {
            return visited_.find(email) != visited_.end();
        }

    private:
        std::unordered_set<std::string> visited_;
        Matrix<std::string> mergedAccounts_;
    };

    Matrix<std::string> AcctMerge::accountsMerge(Matrix<std::string> &accounts) {
        Graph G;

        for(auto const& account: accounts) {
            auto sz = account.size();
            auto & firstEmail = account[1];
            G.add(firstEmail, firstEmail);
            for (int j = 2; j < sz; ++j) {
                auto& email = account[j];
                G.add(firstEmail, email);
            }
        }

        CC cc(G, accounts);
        return cc.mergedAccounts();
    }
}