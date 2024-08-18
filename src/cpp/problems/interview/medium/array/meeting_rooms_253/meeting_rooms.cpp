#include "meeting_rooms.hpp"

#include <algorithm>

/**
 * Space Complexity: O(N)
 * Time Complexity: O(N log N)
 */

namespace algo::interview::medium::meeting_rooms_ii {

    enum RangeType {
        START = 0,
        END = 1
    };

    std::vector<int> getSortedTimes(std::vector<std::vector<int>> &intervals, RangeType which) {
        std::vector<int> times;
        times.reserve(intervals.size());

        std::transform(intervals.begin(), intervals.end(), std::back_inserter(times), [which](auto const &interval) {
            return interval[which];
        });

        std::sort(times.begin(), times.end());
        return times;
    }

    int MeetingRooms::minMeetingRooms(std::vector<std::vector<int>> &intervals) {
        auto startTimes = getSortedTimes(intervals, START);
        auto endTimes = getSortedTimes(intervals, END);

        int usedRooms = 0;
        int start{0}, end{0};

        while (start < intervals.size()) {
            // if there is a meeting room that has been ended by the time a new meeting starts
            if (startTimes[start] >= endTimes[end]) {
                usedRooms -= 1;
                ++end;
            }

            // we are using a meeting room
            ++usedRooms;
            // go to next start time
            ++start;
        }

        return usedRooms;
    }

}