#include "search_in_rotated_array.hpp"

namespace algo::interview::medium::array::search_in_rotated_array_33 {

    int getPivot(std::vector<int>& nums, int start, int end) {
        std::size_t pivot = end;

        while(end >= start) {
            auto mid = start + (end - start)/2;
            if (nums[mid] < nums[pivot]) {
                pivot = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return pivot;
    }

    int binarySearch(std::vector<int>& nums, int start, int end, int target) {
        while (end >= start) {
            auto mid = start + (end - start)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }


    int SearchInRotatedArray::search(std::vector<int> &nums, int target) {
        int lastIndex = static_cast<int>(nums.size()) - 1;
        auto pivot = getPivot(nums, 0, lastIndex);

        auto index = binarySearch(nums, 0, pivot-1, target);
        if (index == -1) {
            index = binarySearch(nums, pivot, lastIndex, target);
        }
        return index;
    }

}