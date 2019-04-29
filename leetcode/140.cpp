vector<string> w(string A, unordered_set<string> B, unordered_map<string, vector<string> > &dp) {
    if(A.size() == 0) return vector<string>();
    if(dp.count(A)) return dp[A];
    vector<string> sol;
    
    for(int i = 0; i < A.size(); i++) {
        string sub = A.substr(0, i+1);
        if(B.find(sub) != B.end()) {
            if(sub == A) {
                sol.push_back(sub);
            } else {
                vector<string> v = w(&A[i+1], B, dp);
                for(string s : v) 
                    sol.push_back(sub + " " + s);
            }
        }
    }
    
    return dp[A] = sol;
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_map<string, vector<string> > dp;
    return w(A, unordered_set<string>(B.begin(), B.end()), dp);
}
