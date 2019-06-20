class Solution {
public:
    const int SHIFT = 1010;
    int sum(vector< vector<int> >& h, vector<int>& nums, int i, long long S) {
        if(S==0 && i == nums.size()) return 1;
        if(i >= nums.size() || S > SHIFT || S < -1 * SHIFT) return 0;
        
        if(h[i][S + SHIFT] != -1) return h[i][S + SHIFT];
        return h[i][S + SHIFT] = sum(h, nums, i+1, S-nums[i]) + sum(h, nums, i+1, S+nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0) return 0;
        
        vector< vector<int> > h(nums.size(), vector<int>(1 + 2 * SHIFT, -1) );    
        return sum(h, nums, 1, (long long)S-nums[0]) + sum(h, nums, 1, (long long)S+nums[0]);
    }
};
