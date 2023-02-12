#ifndef GLIDEA_LEETCODE_MONOTONIC_ARRAY_HPP
#define GLIDEA_LEETCODE_MONOTONIC_ARRAY_HPP

#include <vector>
#include <functional>

namespace algo::problems::leetcode::array::monotonic {

    class MonotonicArray {
    public:
        using Comparator = std::function<bool(const int, const int)>;

    private:
        using It = std::vector<int>::const_iterator;

    private:
        static std::pair<Comparator, It> smallestMonotone(It begin, It end);

    public:
        bool isMonotonic(std::vector<int> &nums);

    };
} // algo::problems::leetcode::arrays::monotonic

#endif //GLIDEA_LEETCODE_MONOTONIC_ARRAY_HPP
