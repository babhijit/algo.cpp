#include "k_largest.hpp"

#include <functional>
#include <queue>

namespace algo::problems::leetcode::pq::k_largest {

    int KLargest::findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int, std::vector<int>, std::less<int>> pq(nums.begin(), nums.end());

        while(--k > 0) {
            pq.pop();
        }

        return pq.top();
    }
}
