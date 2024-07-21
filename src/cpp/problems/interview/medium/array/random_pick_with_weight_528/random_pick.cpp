#include <random_pick.hpp>

#include <numeric>
#include <iterator>

namespace algo::interview::medium::array::random_pick_with_weight {

    /**
     * Time Complexity: O(log (n) )
     * Space Complexity:
     *      ctor: O(n)
     *      pickIndex: O(1)
     */

    RandomPick::RandomPick(std::vector<int> &w) {
        std::partial_sum(w.begin(), w.end(), std::back_inserter(preSum_), std::plus<>());
    }

    int RandomPick::pickIndex() {
        // Generate a random number in the range 0..1
        float randNum = static_cast<float>(std::rand()) / RAND_MAX;
        float target = randNum/preSum_.back();

        // run a linear search to find the target zone
        auto it = std::lower_bound(preSum_.begin(), preSum_.end(), target);
        return std::distance(preSum_.begin(), it);
    }
}