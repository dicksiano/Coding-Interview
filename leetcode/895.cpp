class FreqStack {
public:
    FreqStack() {
        maxi = 0;
    }
    
    void push(int x) {
        freq[x]++;
        maxi = max(maxi, freq[x]);
        freqMap[ freq[x] ].push(x);
    }
    
    int pop() {
        int mostFreq = freqMap[maxi].top();
        freqMap[maxi].pop();
        freq[mostFreq]--;
        if(freqMap[maxi].empty()) maxi--;
        
        return mostFreq;
    }
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int> > freqMap;
    int maxi;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
