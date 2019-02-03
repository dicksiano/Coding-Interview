class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0) { first.push(num); size++; return; }
        size++;
        
        if(num > findMedian()) second.push(num);
        else first.push(num);
        
        balance();
    }
    
    double findMedian() {
        if(size == 0) return 0.0;
        if(second.empty()) return first.top();
        
        if(size%2) return first.top();
        else return (first.top() + second.top()) / 2.0;
    }
    
private:
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int> > second;
    int size;
    
    void balance() {
        if(first.size() < second.size()) {
            first.push(second.top()); 
            second.pop();
        } else if(first.size() > 1 + second.size()) {
            second.push(first.top()); 
            first.pop();
        }        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
