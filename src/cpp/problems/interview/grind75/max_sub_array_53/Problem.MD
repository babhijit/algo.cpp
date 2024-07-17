    int lowerBound(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size()) - 1;

        int lowerBound = -1;
        while (end >= begin) {
            auto mid = begin + (end - begin) / 2;

            if (nums[mid] == target) {
                lowerBound = mid;
                // check for more matches in descending order on the left
                end = mid - 1;
            } else if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return lowerBound;
    }

    int upperBound(std::vector<int> &nums, int target) {
        int begin = 0;
        int end = static_cast<int>(nums.size()) - 1;
        int upperBound = -1;

        while (end >= begin) {
            auto mid = begin + (end - begin) / 2;
            if (nums[mid] == target) {
                upperBound = mid;
                begin = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }

        return upperBound;
    }
