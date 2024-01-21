#pragma once

#include <vector>

namespace algo::problems::leetcode::array::house_robber::detail {

    class MaxHouseRobbery {
    public:
        explicit MaxHouseRobbery(std::vector<int> const &houses) :
                houses_(houses), cache_(houses.size(), -1) {}

        int maxRobbery() {
            return getMaxRobbery(0);
        }

    private:
        int getMaxRobbery(int startFrom) {
            if (not canRob(startFrom)) {
                return 0;
            }

            auto &maxAmount = cache_[startFrom];

            if (not isCached(startFrom)) {
                maxAmount = std::max(getMaxRobbery(startFrom + 1),
                                     getMaxRobbery(startFrom + 2) + houses_[startFrom]);
            }

            return maxAmount;
        }

        [[nodiscard]] inline bool canRob(int i) const {
            return i < houses_.size();
        }

        [[nodiscard]] inline bool isCached(int i) const {
            return cache_[i] > -1;
        }

    private:
        std::vector<int> const &houses_;
        std::vector<int> cache_;
    };

} // algo::problems::leetcode::array::house_robber::detail
