#include "jump_game.hpp"

#include <algorithm>
#include <vector>

namespace algo::problems::leetcode::interview::dp::jump_game {

    bool JumpGame::canJump(std::vector<int> &nums) {
        auto memo = std::vector<Index>(nums.size(), Index::UNKNOWN);
        memo[nums.size() - 1] = Index::GOOD;

        return canJumpFrom(0, nums, memo);
    }

    bool JumpGame::canJumpFrom(const int pos, std::vector<int> &nums, std::vector<Index> &memo) {
        if (memo[pos] != Index::UNKNOWN) {
            return memo[pos] == Index::GOOD ? true : false;
        }

        auto maxAllowedJump = pos + nums[pos];
        auto furthestJump = std::min(maxAllowedJump, static_cast<int>(nums.size()) - 1);
        for(auto nextPos = pos + 1; nextPos <= furthestJump; ++nextPos) {
            if (canJumpFrom(nextPos, nums, memo)) {
                memo[nextPos] = Index::GOOD;
                return true;
            }
        }

        memo[pos] = Index::BAD;
        return false;
    }
}

