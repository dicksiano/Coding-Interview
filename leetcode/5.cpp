class Solution {
public:
    void update(string s, int i, int j, int &start, int &end) {
        if(j-i > end-start) {
            start = i;
            end = j;
        }
    }
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        
        int start = 0, end = 0;
        for(int c = 0; c < s.size(); c++) {
            int i = c, j = c;
            for(; j < (int)s.size()-1 && s[j+1] == s[j]; j++) c = j;
            for(; i >= 0 && j < (int)s.size() && s[i] == s[j]; i--, j++) update(s, i, j, start, end);
        }
        return s.substr(start, end-start+1);
    }
};
