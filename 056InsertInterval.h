/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        
        vector<Interval>::iterator it;
        for (it = intervals.begin(); it != intervals.end() && it->end < newInterval.start; ++it)
            ret.push_back(*it);
        
        if (it == intervals.end())
        {
            ret.push_back(newInterval);
            return ret;
        }
        
        if (it->start > newInterval.end)
        {
            ret.push_back(newInterval);
        }
        else
        {
            int start = min(newInterval.start, it->start);
            for (; it != intervals.end() && it->start <= newInterval.end; ++it);
            --it;
            int end = max(newInterval.end, it->end);
            ret.push_back(Interval(start, end));
            ++it;
        }
        
        for (; it != intervals.end(); ++it)
            ret.push_back(*it);
            
        return ret;
    }
};