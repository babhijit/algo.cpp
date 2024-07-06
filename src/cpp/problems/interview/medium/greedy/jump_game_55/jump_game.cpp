#include "jump_game.hpp"

#include <algorithm>
#include <vector>

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

namespace algo::problems::leetcode::interview::greedy::jump_game {

    bool JumpGame::canJump(std::vector<int> &nums) {
        auto lastPos = static_cast<int>(nums.size()) - 1;
        for (auto i = lastPos; i >= 0; --i) {
            auto maxJump = i + nums[i];
            if (maxJump >= lastPos) {
                lastPos = i;
            }
        }

        // Have we reached the start of the array?
        return lastPos == 0;
    }
}

