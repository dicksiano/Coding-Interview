  class Solution {
public:
    int lso(int x) { return x & (-x); }
    
    vector<int> pickNums(int x, vector<int> v) {
        vector<int> res;
        for(; x > 0; x = x - lso(x))
            res.push_back(v[ log2( lso(x) ) ]);
        return res;
    }
    
    vector<vector<int> > subsets(vector<int>& nums) {
        vector< vector<int> > res;
        for(int i = 0; i < 1<< nums.size(); i++) 
            res.push_back(pickNums(i, nums));
        return res;
    }
};
