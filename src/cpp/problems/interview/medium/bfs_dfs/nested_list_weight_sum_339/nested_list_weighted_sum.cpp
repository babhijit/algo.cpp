#include "nested_list_weighted_sum.hpp"

namespace algo::interview::medium::array::nested_list_weighted_sum {

    /**
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    int weightedNumDfs(int depth, NestedInteger ni) {
        if (ni.isInteger()) {
            return depth * ni.getInteger();
        }

        auto &niList = ni.getList();
        int weightedNumber{};
        for (auto &nestedInt: niList) {
            weightedNumber += weightedNumDfs(depth + 1, nestedInt);
        }
        return weightedNumber;
    }

    int NestedListWeightedSum::depthSum(std::vector<NestedInteger> &nestedList) {
        int sum{};

        for (auto &ni: nestedList) {
            sum += weightedNumDfs(1, ni);
        }

        return sum;
    }
}