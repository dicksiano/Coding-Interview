class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0, j = 0;
        vector<int> mask; mask.assign(260, 0);
        
        for(int i = 0; i < s.size(); i++) {
            mask[ s[i] ] = 1; 
                
            for(j = j+1; (j < s.size()) && !mask[ s[j] ]; j++) 
                mask[ s[j] ] = 1;
                
            maxi = max(maxi, j-i);              
            for(;  s[i] != s[j]; i++) mask[ s[i] ] = 0;     
        }
        return maxi;
    }
};
