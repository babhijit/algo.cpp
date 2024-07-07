#include "container_with_most_water.hpp"

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

namespace algo::problems::leetcode::interview::greedy::container_with_max_water {

    int ContainerWithMostWater::maxArea(std::vector<int> &height) {
        std::int32_t maxArea{};

        std::int32_t left = 0;
        std::int32_t right = height.size() - 1;

        while (left < right) {
            auto width = right - left;
            auto leftHt = height[left];
            auto rightHt = height[right];
            auto area = std::min(leftHt, rightHt) * width;
            maxArea = std::max(maxArea, area);

            if (leftHt > rightHt) {
                --right;
            } else if (rightHt > leftHt) {
                ++left;
            } else if (right - left > 1) {
                if (height[left + 1] > height[right - 1]) {
                    --right;
                } else {
                    ++left;
                }
            } else {
                break;
            }
        }

        return maxArea;
    }
}