class Solution {
public:
    int characterReplacement(string s, int k) {
        int j = 0, maxi = 0, cache[130] = {0};
        for(int i = 0; i < (int)s.size(); i++) {
            maxi = max(maxi, ++cache[ s[i] ]);
            if(i-j+1 > maxi+k) cache[ s[j++] ]--;
        }
        return s.size()-j;
    }
};
