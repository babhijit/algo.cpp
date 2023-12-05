#include <algorithm>
#include "monotonic_array.hpp"

namespace algo::problems::leetcode::array::monotonic {

    MonotonicArray::Comparator lessEqual = [](const int a, const int b) {
        return std::less_equal<>()(a, b);
    };;

    MonotonicArray::Comparator greaterEqual = [](const int a, const int b) {
        return std::greater_equal<>()(a, b);
    };;


    std::pair<MonotonicArray::Comparator, MonotonicArray::It> MonotonicArray::smallestMonotone(It begin, It end) {
        auto it = std::find_if_not(begin, end, [&begin](auto a) { return std::equal_to()(a, *begin); });
        if (it != end) {
            Comparator comp = lessEqual(*it, *std::prev(it)) ? lessEqual : greaterEqual;
            return {comp, it};
        }
        return {nullptr, it};
    }

    bool MonotonicArray::isMonotonic(std::vector<int> &nums) {
        auto monotoneTill = smallestMonotone(std::begin(nums), std::end(nums));
        auto comparator = monotoneTill.first;

        for (auto it = monotoneTill.second; it != std::end(nums); ++it) {
            if (!comparator(*it, *std::prev(it)))
                return false;
        }

        return true;
    }
}