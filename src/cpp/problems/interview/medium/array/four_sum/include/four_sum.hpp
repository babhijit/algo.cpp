#pragma once

#include <cstdint>
#include <utility>
#include <vector>

namespace algo::interview::medium::array::four_sum {

    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    class FourSum {

    public:
        Matrix<int> fourSum(std::vector<int> &nums, int target);

    private:
        std::vector<std::pair<int, int>> getAllTwoSums(std::vector<int>& nums,
                                                       std::size_t start, std::size_t end,
                                                       std::int64_t target);
    };

}