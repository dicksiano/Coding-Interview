class Solution {
public:
    void insertNew(vector<Interval>& interv, Interval x) {        
        int m, i = 0, j = interv.size()-1;
        for(m = (i+j)/2; i < j; m = (i+j)/2) {
            if(x.start <= interv[m].start) j = m;  
            else i = m+1;
        }
        if(x.start < interv[i].start) interv.insert(interv.begin()+i, x);
        else interv.insert(interv.begin()+i+1, x);
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0) return vector<Interval>{newInterval};
        int i = 0, j;
        
        insertNew(intervals, newInterval);
        for(i = 0; i < intervals.size()-1; i++) {
            if(intervals[i].end >= intervals[i+1].start) {
                for(j = i+1; j < intervals.size() && intervals[i].end >= intervals[j].start; j++) 
                    intervals[i].end = max(intervals[i].end, intervals[j].end);
                intervals.erase(intervals.begin()+i+1, intervals.begin()+j);
            }
        }
        
        return intervals;
    }
};
