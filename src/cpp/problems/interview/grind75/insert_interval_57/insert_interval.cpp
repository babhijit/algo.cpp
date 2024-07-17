#include "insert_interval.hpp"

#include <vector>

namespace algo::interview::grind75::insert_interval {

    enum IntervalRange {
        LO = 0,
        HI = 1
    };

    IntMatrix InsertInterval::insert(IntMatrix &intervals, std::vector<int> &newInterval) {
        IntMatrix mergedIntervals;

        int i = 0;
        // intervals preceding newInterval
        while((i < intervals.size()) and (newInterval[LO] > intervals[i][HI]) ) {
            mergedIntervals.push_back(intervals[i]);
            ++i;
        }

        mergedIntervals.push_back(newInterval);

        auto& lastInterval = mergedIntervals.back();
        // overlapping intervals
        while ((i < intervals.size()) and (intervals[i][LO] <= newInterval[HI])) {
            lastInterval[LO] = std::min(lastInterval[LO], intervals[i][LO]);
            lastInterval[HI] = std::max(lastInterval[HI], intervals[i][HI]);
            ++i;
        }

        while (i < intervals.size()) {
            mergedIntervals.push_back(intervals[i]);
            ++i;
        }

        return mergedIntervals;
    }
}