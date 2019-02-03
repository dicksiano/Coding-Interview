struct comp {
    bool operator() (pair<int, int> p1, pair<int, int> p2) { return p1.second > p2.second; }
} compare;

class Solution {
public:    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) freq[ nums[i] ]++;
        
        vector< pair<int, int> > f(freq.begin(), freq.end());
        sort(f.begin(), f.end(), compare);
        
        vector<int> res;
        for(int i = 0; i < k; i++) res.push_back(f[i].first);
        return res;
    }
};
