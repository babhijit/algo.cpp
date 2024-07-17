#include "insert_interval.hpp"

#include <vector>

namespace algo::interview::grind75::insert_interval {

    enum IntervalRange {
        LO = 0,
        HI = 1
    };

    bool isOverlapping(std::vector<int> const &a, std::vector<int> const &b) {
        if (a[LO] < b[LO]) {
            return a[HI] >= b[LO];
        }
        return b[HI] >= a[LO];
    }

    IntMatrix InsertInterval::insert(IntMatrix &intervals, std::vector<int> &newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        auto insertInterval = [&newInterval](IntMatrix &result, std::vector<int> &interval) {
            if (result.empty()) {
                // is newInterval before interval
                if (newInterval[HI] < interval[LO]) {
                    result.push_back(newInterval);
                }
                result.push_back(interval);
            } else {
                auto &runningInterval = result.back();

                // check if newInterval is sandwiched between runningInterval and interval
                if ((newInterval[LO] > runningInterval[HI]) and
                    (newInterval[HI] < interval[LO])) {
                    result.push_back(newInterval);
                }

                result.push_back(interval);
            }

            auto &insertedInterval = result.back();
            if (isOverlapping(insertedInterval, newInterval)) {
                insertedInterval[LO] = std::min(insertedInterval[LO], newInterval[LO]);
                insertedInterval[HI] = std::max(insertedInterval[HI], newInterval[HI]);
            }
        };

        IntMatrix nonOverlappingIntervals;
        insertInterval(nonOverlappingIntervals, intervals[0]);

        for (auto i = 1; i < intervals.size(); ++i) {
            auto &runningInterval = nonOverlappingIntervals.back();
            auto &interval = intervals[i];

            // check if the new interval overlaps with the running interval
            if (isOverlapping(runningInterval, interval)) {
                runningInterval[HI] = std::max(interval[HI], runningInterval[HI]);
            } else {
                insertInterval(nonOverlappingIntervals, interval);
            }
        }

        // edge case: check if newInterval insertion at the end
        if (newInterval[LO] > nonOverlappingIntervals.back()[HI]) {
            nonOverlappingIntervals.push_back(newInterval);
        }

        return nonOverlappingIntervals;
    }
}