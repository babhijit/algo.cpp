#include "jump_game.hpp"

#include <algorithm>

namespace algo::problems::leetcode::interview::backtracing::jump_game {

    bool JumpGame::canJump(std::vector<int> &nums) {
        return canJumpFrom(0, nums);
    }

    bool JumpGame::canJumpFrom(int pos, std::vector<int> &nums) {
        if (pos == nums.size() - 1) {
            return true;
        }

        auto maxAllowedJump = pos + nums[pos];
        int furthestStep = std::min(maxAllowedJump, static_cast<int>(nums.size() - 1));
        for (auto nextPos = furthestStep; nextPos > pos; --nextPos) {
            if (canJumpFrom(nextPos, nums)) {
                return true;
            }
        }

        return false;
    }
}

