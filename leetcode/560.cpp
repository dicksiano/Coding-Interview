class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        
        int res = 0;
        vector<int> dp(nums);
        
        if(dp[0] == k) res++;
        for(int i = 1; i < nums.size(); i++) {
            dp[i] += dp[i-1];
            if(dp[i] == k) res++;
        }
        
        for(int i = 1; i < nums.size(); i++) 
            for(int j = i; j < nums.size(); j++) {
                dp[j] = dp[j] - nums[i-1];
                if(dp[j] == k) res++;
            }
        
        return res;
    }
};
