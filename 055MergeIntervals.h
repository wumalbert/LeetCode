/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool intervalComp(Interval i1, Interval i2)
{
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (intervals.size() <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), intervalComp);
        
        vector<Interval> ret;
        
        vector<Interval>::iterator it = intervals.begin();
        int currStart = it->start;
        int currEnd = it->end;
        ++it;
        while (it != intervals.end())
        {
            
            if (it->start <= currEnd) currEnd = max(currEnd, it->end);
            else
            {
                ret.push_back(Interval(currStart, currEnd));
                
                currStart = it->start;
                currEnd = it->end;
            }
            ++it;
        }
        ret.push_back(Interval(currStart, currEnd));
        
        return ret;
    }
};