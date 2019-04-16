class Solution {
public:
    void check(string s, int i, int j, int &count) {
        while(i >=0 && j < s.size() && s[i--] == s[j++]) count++;    
    }
    
    int countSubstrings(string s) {
        int sol = 0;
        for(int i = 0; i < s.size(); i++) {
            check(s, i, i, sol);
            check(s, i, i+1, sol);
        }
        return sol;
    }
};
