#include "include/combination_sum.h"

#include <stdexcept>

namespace algo::problems::leetcode::maths::combination_sum {

    CombinationSum::IntMatrix CombinationSum::combinationSum(CombinationSum::IntRowVector &candidates, int target) {
        IntMatrix solutions;
        IntRowVector combinations;

        backtrackDfs(candidates, 0, target, combinations, 0, solutions);

        return solutions;
    }

    void CombinationSum::backtrackDfs(CombinationSum::IntRowVector &candidates,
                                      int pointer,
                                      int target,
                                      IntRowVector& combinations,
                                      int currentSum,
                                      CombinationSum::IntMatrix &solutions) {
        if (target < currentSum) {
            return;
        }

        if (target == currentSum) {
            solutions.push_back(combinations);
            return;
        }

        // try out the remaining combinations.
        for (int i = pointer; i < candidates.size(); ++i) {
            combinations.push_back(candidates[i]);
            backtrackDfs(candidates, i, target, combinations, currentSum + candidates[i], solutions);

            // current value has already been check out by backtrackDfs. So move on to next
            combinations.pop_back();
        }
    }

} // algo::problems::leetcode::maths::combination_sum
