#include "elm_in_sorted_array.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::elm_in_sorted_array {

    int ElementInSortedArray::findSpecialInteger(std::vector<int> &arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Array cannot be empty");
        }

        auto N = arr.size();
        auto target = QUARTER * N;

        auto active = arr[0];
        auto count = 1;

        for(auto i = 1; i < N; ++i) {
            if (arr[i] == active) {
                if (++count > target) {
                    return active;
                }
            } else {
                active = arr[i];
                count = 1;
            }
        }

        return active;
    }
}