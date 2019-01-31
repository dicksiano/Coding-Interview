class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0, j = 1;
        int mask[260]; memset(mask, 0, sizeof(mask));
        
        for(int i = 0; i < s.size(); i++) {
            if(!mask[ s[i] ]) {
                mask[ s[i] ] = 1; 
                
                for(j = max(j, i+1); (j < s.size()) && !mask[ s[j] ]; j++) 
                    mask[ s[j] ] = 1;
                
                maxi = max(maxi, j-i);   
            }
            cout << i << " - " << s[i] << ", " << j << ": " << maxi << endl; 
            if(s[i] != s[j] || i == j-1) mask[ s[i] ] = 0;     
        }
        return maxi;
    }
};
