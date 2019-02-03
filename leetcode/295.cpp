class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() { }
    
    void addNum(int num) {
        if(first.size() == 0) { first.push(num); return; }
        
        if(num > findMedian()) second.push(num);
        else first.push(num);
        
        balance();
    }
    
    double findMedian() {
        if( (first.size() + second.size()) % 2) return first.top();
        else return (first.top() + second.top()) / 2.0;
    }
    
private:
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int> > second;
    
    void balance() {
        if(first.size() < second.size()) { first.push(second.top()); second.pop(); } 
        else if(first.size() > 1 + second.size()) { second.push(first.top()); first.pop(); }        
    }
};
