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

    void copySorted(std::vector<int>& tgt, std::vector<std::vector<int>>& source, RangeType which) {
        for (std::size_t i = 0; i < source.size(); ++i) {
            tgt.push_back(source[i][which]);
        }
        std::sort(tgt.begin(), tgt.end(),
                  [](const int& a, const int& b) { return a < b; });
    }

    int MeetingRooms::minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::vector<int> startTimes;
        startTimes.reserve(intervals.size());
        copySorted(startTimes, intervals, START);

        std::vector<int> endTimes;
        endTimes.reserve(intervals.size());
        copySorted(endTimes, intervals, END);

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