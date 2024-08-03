#include "subarray_sum.hpp"

#include <unordered_map>

/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

namespace algo::interview::medium::array::continuous_subarray_sum {

    bool SubarraySum::checkSubarraySum(std::vector<int> &num, int k) {
        std::unordered_map<int, int> moduloCache{{0,-1}};
        int total{0};

        // logical construct to put a 0 before the array begins
        // Edge Case: if the first element is 0 then subarrayLength will return 1
        for (std::size_t itr = 0; itr < num.size(); ++itr) {
            total += num[itr];
            int modulo = total % k;
            if (not moduloCache.contains(modulo)) {
                moduloCache[modulo] = itr;
            } else {
                auto subarrayLength = itr - moduloCache[modulo];
                if (subarrayLength > 1) {
                    return true;
                }
            }
        }
        return false;
    }
}