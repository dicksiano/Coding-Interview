/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct comparator {
    bool operator() (Interval a, Interval b) { return a.start < b.start; }
} comp;

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        
        int i = 0, j = 1;
        sort(intervals.begin(), intervals.end(), comp);
        
        for(; j < intervals.size();) {
            while(j < intervals.size() && intervals[i].end >= intervals[j].start) {
                intervals[i].end = max(intervals[i].end, intervals[j].end);
                j++;
            }            
            if(j < intervals.size()) intervals[++i] = intervals[j++];
        }
        
        intervals.erase(intervals.begin()+i+1, intervals.end());
        return intervals;
    }
};
