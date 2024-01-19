#include "climbing_stairs.hpp"

#include <vector>

namespace algo::problems::leetcode::maths::climbing_stairs {

    int ClimbingStairs::climbStairs(int n) {

        if (n < 3) {
            return n;
        }

        std::vector<int> waysToReach(n + 1, 0);
        waysToReach[1] = 1; // level 1 can be reached in only 1 way (1 step)
        waysToReach[2] = 2; // level 2 can be reached in two ways (taking 2 1 steps or directly taking 2 steps)

        // this naturally leads to fibonacci sequence
        for (auto i = 3; i <= n; ++i) {
            waysToReach[i] = waysToReach[i - 1] + waysToReach[i - 2];
        }

        return waysToReach[n];
    }

}