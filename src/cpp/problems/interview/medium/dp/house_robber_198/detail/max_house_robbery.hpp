#pragma once

#include <vector>
#include <stdexcept>

namespace algo::interview::medium::dp::house_robber::detail {

    class MaxHouseRobbery {
    public:
        explicit MaxHouseRobbery(std::vector<int> const &houses) :
                houses_(houses), maxRobbedAmount_(houses.size() + 1, 0) {}

        int maxRobbery() {
            const auto N = houses_.size();
            maxRobbedAmount_[N - 1] = houses_[N - 1];

            for (int i = N - 2; i >= 0; --i) {
                // for `i + 2 = N` to work, maxRobbedAmount_[N] = 0
                maxRobbedAmount_[i] = std::max(maxRobbedAmount_[i + 1],
                                               maxRobbedAmount_[i + 2] + houses_[i]);
            }

            return maxRobbedAmount_[0];
        }

    private:
        std::vector<int> const &houses_;
        std::vector<int> maxRobbedAmount_;
    };

} // algo::interview::medium::dp::house_robber::detail
