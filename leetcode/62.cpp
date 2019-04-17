class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(i+1 < n) dp[i+1][j] += dp[i][j];
                if(j+1 < m) dp[i][j+1] += dp[i][j];
            }
        return dp[n-1][m-1];
    }
};
