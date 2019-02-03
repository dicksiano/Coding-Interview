class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        int res = 1;
        
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) res = max(res, dp[i] = max(dp[i], 1 + dp[j]) );
        return res;
    }
};
