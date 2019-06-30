class Solution {
public:
    void dfs(string s, vector<string> &ans, int iLast, int jLast, vector<char> alpha) {
        for(int i = iLast, diff = 0; i < s.size(); i++) {
            diff += (s[i] == alpha[0]) ? 1 : ((s[i] == alpha[1]) ? -1 :0);
            
            if(diff < 0) {
                for(int j = jLast; j < s.size(); j++)
                    if(s[j] == alpha[1] && (j == jLast || s[j-1] != alpha[1]) ) 
                        dfs(s.substr(0, j) + s.substr(j+1, s.size()), ans, i, j, alpha);
                return;
            }
        }
        reverse(s.begin(), s.end());
        if(alpha[0] == '(') dfs(s, ans, 0, 0, vector<char>{')', '('});
        else ans.push_back(s);   
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        dfs(s, ans, 0, 0, vector<char>{'(', ')'});
        return ans;
    }
};
