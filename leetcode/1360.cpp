class Solution {
public:
    bool bis(int i) {
        if(!(i%400)) return true;
        if(!(i%4) && i%100) return true;
        
        return false;
    }
    
    int year(int i) { return (bis(i) ? 366 : 365); }
    
    int month(int i, int y) {
        unordered_set<int> h = {1,3,5,7,8,10,12};

        if(h.find(i) != h.end()) return 31;        
        if(i == 2 ) return (bis(y) ? 29 : 28);
        return 30;
    }
    
    long long score(int y, int m, int d) {
        long long t = 0;
        for(int i = 1970; i < y; i++) t+= year(i);
        for(int i = 1;    i < m; i++) t+= month(i, y);
        
        return t + d;
    }
    int daysBetweenDates(string date1, string date2) {
        int y1 = stoi(date1.substr(0,4)), m1 = stoi(date1.substr(5,2)), d1 = stoi(date1.substr(8,2));
        int y2 = stoi(date2.substr(0,4)), m2 = stoi(date2.substr(5,2)), d2 = stoi(date2.substr(8,2));
        
        long long t1 = score(y1,m1,d1), t2 = score(y2,m2,d2);
        return abs(t2-t1);
    }
};
