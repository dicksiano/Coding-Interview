struct comparator {
    bool operator() (Interval a, Interval b) { 
        if(a.end != b.end) return a.end < b.end;
        return a.start < b.start; 
    }
} comp;


class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {        
        sort(intervals.begin(), intervals.end(), comp);
        int end = INT_MIN, res = 0;
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i].start >= end) end = intervals[i].end;
            else res++;
        }
        return res;        
    }
    
    bool isOverlapping(Interval a, Interval b) { return (a.end > b.start) || (a.start == b.start && a.end == b.end); }
};
