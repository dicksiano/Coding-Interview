class Solution {
public:
    bool worldBreak(string s, unordered_set<string> dict) {
        int N = s.size();
        int dp[N][N] = {};

        for(int step = 0; step < N; step++)
            for(int i = 0, j = i + step; i < N - step; i++, j++) {
                if(dict.find(s.substr(i,j-i+1)) != dict.end()) dp[i][j] = 1;
                for(int k = i; !dp[i][j] && k < j; k++)
                    if(dp[i][k] && dp[k+1][j]) 
                        dp[i][j] = 1;
            }           
        return dp[0][N-1];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return worldBreak(s, unordered_set<string>(wordDict.begin(), wordDict.end()));
    }
};
