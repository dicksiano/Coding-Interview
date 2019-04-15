class Solution {
public:
    bool isValid(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    char low(char c) { 
        if(c >= '0' && c <= '9') return c;
        if(c >= 'a' && c <= 'z') return c;
        return c -'A' + 'a';
    }
    
    bool isPalindrome(string s) {
        if((int)s.size() == 0) return true;
        int i = 0, j = s.size()-1;
        while(i<j) {
            while(i<j && !isValid(s[i])) i++;
            while(i<j && !isValid(s[j])) j--;
            if(i<j && low(s[i++]) != low(s[j--])) return false;
        }
        return true;
    }
};
