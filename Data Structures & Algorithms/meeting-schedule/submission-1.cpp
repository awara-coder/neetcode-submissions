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


struct IntervalComparator {
    bool operator()(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // We can easily check this by checking if any of them are overlapping.
        // sort the array first according to start time.
        sort(intervals.begin(), intervals.end(), IntervalComparator());

        for (int i = 1; i < intervals.size(); i++) {
            // If this is overlapping with previous, return false
            if (intervals[i - 1].end > intervals[i].start) {
                return false;
            }
        }

        return true;
    }
};
