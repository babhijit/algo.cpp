#include "nested_list_weighted_sum.hpp"

#include <queue>
#include <vector>


namespace algo::interview::medium::array::nested_list_weighted_sum {

#ifdef DFS

    /**
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     **/
    int weightedNumDfs(int depth, std::vector<NestedInteger> const& nestedList) {
        int sum{0};

        for(auto& ni: nestedList) {
            if (ni.isInteger()) {
                sum += (depth * ni.getInteger());
            } else {
                sum += weightedNumDfs(depth + 1, ni.getList());
            }
        }

        return sum;
    }

#else
    int getCurLvlSum(std::queue<NestedInteger>& q) {
        std::queue<NestedInteger> nxtLvlQ;
        int sum{0};

        while(not q.empty()) {
            auto ni = q.front();
            q.pop();

            if (ni.isInteger()) {
                sum += ni.getInteger();
            } else {
                nxtLvlQ.push_range(ni.getList());
            }
        }

        q.swap(nxtLvlQ);
        return sum;
    }

    /**
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    int weightedSumBfs(std::vector<NestedInteger> const& nestedList) {
        int sum{0};

        std::queue<NestedInteger> q;
        q.push_range(nestedList);

        int depth = 1;
        while(not q.empty()) {
            sum += depth * getCurLvlSum(q);
            ++depth;
        }

        return sum;
    }
#endif

    int NestedListWeightedSum::depthSum(std::vector<NestedInteger> &nestedList) {
#ifdef DFS
        return weightedNumDfs(1, nestedList);
#else
        return weightedSumBfs(nestedList);
#endif
    }
}