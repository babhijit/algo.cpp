#include "merge_intervals.hpp"

#include <algorithm>

/**
 * Time Complexity: O (n * log n)
 * Space Complexity: O ( n ) or O (log n)
 */

namespace algo::interview::medium::array::merge_intervals {

    enum Length {
        Start = 0,
        End = 1
    };

    Matrix MergeIntervals::merge(Matrix &intervals) {

        std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return (a[Start] < b[Start]);
        });

        Matrix result;
        std::vector<int> window = intervals[0];

        for (auto i = 1; i < intervals.size(); ++i) {
            auto &current = intervals[i];

            // no overlapping here
            if (current[Start] > window[End]) {
                result.push_back(window);
                window = current;
                continue;
            }

            window[Start] = std::min(current[Start], window[Start]);
            window[End] = std::max(current[End], window[End]);
        }

        result.push_back(window);

        return result;
    }
}