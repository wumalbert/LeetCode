/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool MyComp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> ret;
        if (intervals.empty()) return ret;
        sort(intervals.begin(), intervals.end(), MyComp);
        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start > ret.back().end) {
                ret.push_back(intervals[i]);
            } else if (intervals[i].end > ret.back().end) {
                ret.back().end = intervals[i].end;
            }
        }
        return ret;
    }
};