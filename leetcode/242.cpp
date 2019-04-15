class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int h1[30] = {0}, h2[30] = {0};
        for(int i = 0; i < (int)s.size(); i++) {
            h1[ s[i] - 'a' ]++;
            h2[ t[i] - 'a' ]++;
        }
        for(int i = 0; i < 30; i++)
            if(h1[i] != h2[i]) return false;
        return true;
    }
};
