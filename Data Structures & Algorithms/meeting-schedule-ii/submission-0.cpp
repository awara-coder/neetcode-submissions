/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        /*
        Thinking process:
        1. We need to find out max number of interval overlaps at a given time.
        2. we can do prefix sum sort of approach.
        3. map[time] -> meeting count
        meeting count = number of meetings simultaneusly happening after and at
        */

        // We need sorted map in order to iterate chronologically
        map<int, int> meetingCount;
        for (const auto &interval : intervals) {
            // Meeting starts at interval.start
            meetingCount[interval.start]++;

            // Meeting ends at interval.end
            meetingCount[interval.end]--;
        }

        int maxMeetingCount = 0;
        int currentMeetingCount = 0;
        // Iterate chronologically and figure out the meetings happening at time t
        for (auto [time, meetingCounter]: meetingCount) {
            currentMeetingCount += meetingCounter;
            maxMeetingCount = max(maxMeetingCount, currentMeetingCount);
        }

        return maxMeetingCount;
    }
};
