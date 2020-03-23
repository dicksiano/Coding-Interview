class Solution {
public:
    string longestPrefix(string &s) {
        unsigned long p = 1, maxi = 0, mod = 1000000007, N = s.size();
        unsigned long h1 = 0, h2 = 0;
        
        for (int i = 0; i < N - 1; i++,  p = (p * 26) % mod) {            
            h1 = (h1 * 26 + s[i]) % mod;
            h2 = (h2 + p * s[N -1 -i]) % mod;
            
            if (h1 == h2) maxi = i+1;
        }
        return s.substr(0, maxi);
    }
};
