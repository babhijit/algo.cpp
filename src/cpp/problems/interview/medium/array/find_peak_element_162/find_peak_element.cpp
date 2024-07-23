#include "find_peak_element.hpp"

#include <stdexcept>

namespace algo::interview::medium::array::find_peak_element {

    int FindPeakElement::findPeakElement(std::vector<int> &nums) {
        int left = 0;
        int lastIndex = static_cast<int>(nums.size()) - 1;
        int right = lastIndex;

        while (right > left) {
            auto mid = left + (right - left) / 2;
            // check for peak towards right
            if ((mid < lastIndex) and (nums[mid] < nums[mid + 1])) {
                left = mid + 1;
            }
            // check for peak towards left
            else if ((mid > 0) and (nums[mid] < nums[mid - 1])) {
                right = mid - 1;
            }
            // we have reached peak
            else {
                return mid;
            }
        }

        // single element array!
        return left;
    }
}