class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        if(nums.size() < 2) return nums[0];
        
        int N = nums.size(), maxi = 0;
        int dp[N] = {0};
        
        dp[0] = nums[0];
        dp[1] = nums[1];
        maxi = max(dp[0], dp[1]);
        
        for(int i = 2; i < N; i++) {
            dp[i] = nums[i] + (i > 2 ? max(dp[i-2], dp[i-3]) : dp[i-2]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
