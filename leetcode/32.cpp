class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> p;
        for(int i = 0; i < s.size(); i++) {
            if(!p.empty() && s[ p.top() ] == '(' && s[i] == ')') p.pop();
            else p.push(i);
        }
        
        int maxi = 0, cur = s.size();
        while(!p.empty()) {
            maxi = max(maxi, cur - p.top() - 1);
            cur = p.top(); 
            p.pop();
        }
        
        maxi = max(maxi, cur); 
        return maxi;
    }
};
