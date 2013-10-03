/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution01 {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int low = 0, high = intervals.size()-1;
        // find the start_index for newInterval.start
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (newInterval.start <= intervals[mid].end) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int start_index = low;
        // find the end_index for newInterval.end
        low = 0;
        high = intervals.size()-1;
        while (low <= high) {
            int mid = low + (high-low >> 1);
            if (newInterval.end < intervals[mid].start) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int end_index = high;
        
        vector<Interval> ret(intervals.begin(), intervals.begin() + start_index);
        if (start_index <= end_index) {
            newInterval.start = min(newInterval.start, intervals[start_index].start);
            newInterval.end = max(newInterval.end, intervals[end_index].end);
        }
        ret.push_back(newInterval);
        ret.insert(ret.end(), intervals.begin()+end_index+1, intervals.end());
        return ret;
    }
};
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> ret;
        int i = 0;
        for (i = 0; i < intervals.size() && intervals[i].end < newInterval.start; ++i) {
            ret.push_back(intervals[i]);
        }
        if (intervals.size() == i) {
            ret.push_back(newInterval);
            return ret;
        }
        if (intervals[i].start > newInterval.end) {
            ret.push_back(newInterval);
        } else {
            newInterval.start = min(intervals[i].start, newInterval.start);
            for (++i; i < intervals.size() && intervals[i].start <= newInterval.end; ++i) {}
            newInterval.end = max(intervals[i-1].end, newInterval.end);
            ret.push_back(newInterval);
        }
        for (; i < intervals.size(); ++i) {
            ret.push_back(intervals[i]);
        }
        return ret;
    }
};
