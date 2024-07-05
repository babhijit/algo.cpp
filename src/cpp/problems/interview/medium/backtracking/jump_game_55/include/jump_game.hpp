#pragma once

#include <vector>

namespace algo::problems::leetcode::interview::backtracing::jump_game {

    class JumpGame {
    public:
        bool canJump(std::vector<int>& nums);
    private:
        bool canJumpFrom(int pos, std::vector<int> &nums);
    };

}