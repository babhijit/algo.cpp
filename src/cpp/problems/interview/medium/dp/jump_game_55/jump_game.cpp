#include "jump_game.hpp"

#include <algorithm>
#include <vector>

namespace algo::problems::leetcode::interview::dp::jump_game {

    bool JumpGame::canJump(std::vector<int> &nums) {
        auto memo = std::vector<bool>(nums.size(), false);
        const int lastIndex = static_cast<int>(nums.size()) - 1;
        memo[lastIndex] = true;

        // start from the second last element; last element is always good and is also the destination
        for (int i = lastIndex - 1; i >= 0; --i) {
            auto maxAllowedJump = i + nums[i];
            auto furthestJump = std::min(maxAllowedJump, lastIndex);
            for (int j = i + 1; j <= furthestJump; ++j) {
                if (memo[j]) {
                    memo[i] = true;
                    break;
                }
            }
        }

        return memo[0];
    }
}

