#pragma once

#include <vector>

namespace algo::interview::medium::array::random_pick_with_weight {

    class RandomPick {
    public:
        explicit RandomPick(std::vector<int>& w);
        int pickIndex();
    private:
        std::vector<int> preSum_;
    };

}