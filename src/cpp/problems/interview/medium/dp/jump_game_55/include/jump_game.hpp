#pragma once

#include <vector>

namespace algo::problems::leetcode::interview::dp::jump_game {

    class JumpGame {
    private:
        enum class Index {
            GOOD,
            BAD,
            UNKNOWN
        };
    public:
        bool canJump(std::vector<int>& nums);

    private:
        bool canJumpFrom(const int pos, std::vector<int> &nums, std::vector<Index> &memo);
    };

}