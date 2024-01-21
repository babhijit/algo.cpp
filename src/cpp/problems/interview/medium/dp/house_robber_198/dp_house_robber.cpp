#include "dp_house_robber.hpp"

#include "max_house_robbery.hpp"

namespace algo::interview::medium::dp::house_robber {

    int HouseRobber::rob(std::vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        return detail::MaxHouseRobbery(nums).maxRobbery();
    }
}