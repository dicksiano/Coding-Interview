class Solution {
public:
    int backtrack(vector<int> &dp, int n) {
        if(dp[n] != INT_MAX) return dp[n];
        
        for(int i = 1; i * i <= n; i++)
            dp[n] = min(dp[n], 1 + backtrack(dp, n - i * i));
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        return backtrack(dp, n);
    }
};
