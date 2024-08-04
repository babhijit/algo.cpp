#include "friends.hpp"

#include <unordered_map>

/**
 * Time Complexity: O(N*N)
 * Space Complexity: O(1)
 */

namespace algo::interview::medium::array::friends {

    bool canMakeFriendRequests(int ageX, int ageY) {
        if (ageY > ageX) {
            return false;
        }

        if (ageY <= ((0.5 * ageX) + 7)) {
            return false;
        }

        return true;
    }

    int Friends::numFriendsRequests(std::vector<int> &ages) {
        std::unordered_map<int, int> ageGroups;
        for (int age : ages) {
            ageGroups[age] += 1;
        }

        int requests{0};
        for (auto [ageX, countX]: ageGroups) {
            for (auto [ageY, countY]: ageGroups) {
                if (canMakeFriendRequests(ageX, ageY)) {
                    if (ageX == ageY) {
                        // eliminate self request
                        requests += ((countX - 1) * countY);
                    } else {
                        requests += (countX * countY);
                    }
                }
            }
        }

        return requests;
    }
}