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
        // We can use a map and add chronological order of interval events

        map<int, int> roomCountEvent;
        for (const auto& interval: intervals) {
            roomCountEvent[interval.start]++;
            roomCountEvent[interval.end]--;
        }

        // Go through chronological events in order and track room count
        int maxRoomCount = 0;
        int currentRoomCount = 0;
        for (const auto&[time, roomCount]: roomCountEvent) {
            currentRoomCount += roomCount;
            maxRoomCount = max(maxRoomCount, currentRoomCount);
        }

        return maxRoomCount;
    }

};
