#include "house_robber.hpp"

#include "max_house_robbery.hpp"

#include <cassert>

namespace algo::problems::leetcode::array::house_robber {

    int HouseRobber::rob(std::vector<int> &nums) {
        assert(not nums.empty() && "Size of nums must be at least 1");

        return detail::MaxHouseRobbery(nums).maxRobbery();
    }
}