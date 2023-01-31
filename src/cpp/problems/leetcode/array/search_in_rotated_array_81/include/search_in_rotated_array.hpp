#ifndef ALGO_CPP_SEARCH_IN_ROTATED_ARRAY_HPP
#define ALGO_CPP_SEARCH_IN_ROTATED_ARRAY_HPP

#include <functional>
#include <vector>

namespace algo::problems::leetcode::array::search_in_rotated_array {

    class SearchInRotatedArray {
        std::less<int> less;
        std::less_equal<int> less_equal;
        std::greater_equal<int> greater_equal;
        std::equal_to<int> equal_to;

    public:
        bool search(std::vector<int> &nums, int target);

        bool can_use_binary_search(std::vector<int>::iterator start, std::vector<int>::iterator mid);
    };

}


#endif //ALGO_CPP_SEARCH_IN_ROTATED_ARRAY_HPP
