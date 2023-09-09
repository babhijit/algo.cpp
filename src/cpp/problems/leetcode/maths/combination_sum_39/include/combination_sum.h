#ifndef ALGO_CPP_COMBINATION_SUM_H
#define ALGO_CPP_COMBINATION_SUM_H

#include <vector>

namespace algo::problems::leetcode::maths::combination_sum {

    class CombinationSum {
    public:
        using IntRowVector = std::vector<int>;
        using IntMatrix = std::vector<IntRowVector>;

        IntMatrix combinationSum(IntRowVector& candidates, int target);

    public:
        void backtrackDfs(IntRowVector& candidates,         // candidates
                          int pointer,                      // current pointer showing the number of candidates used
                          int target,                       // target
                          IntRowVector& combinations,       // current combination in usage
                          int currentSum,                   // current sum of combination in usage
                          IntMatrix& solutions);            // list of solutions reached
    };

} // algo::problems::leetcode::maths::combination_sum


#endif //ALGO_CPP_COMBINATION_SUM_H
