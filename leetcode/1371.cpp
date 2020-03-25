class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> last(32, INT_MIN); last[0] = -1;
        unordered_map<char, int> h({ {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} });
        int sol = 0, mask = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if(h.count( s[i] ) ) mask ^= 1 << h[ s[i] ];
            (last[mask] == INT_MIN) ? (last[mask] = i) : sol = max(sol, i - last[mask]);
        }        
        return sol;
    }
};
