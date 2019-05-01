class Solution {
public:
    bool all(unordered_map<char, int> &f) {
        for(auto it = f.begin(); it != f.end(); it++)
            if(f[it->first] > 0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        unordered_set<char> h(t.begin(), t.end());
        unordered_map<char, int> f;
        for(char c : t) f[c]++;
        
        int i = 0, j = 0, mini = INT_MAX, st = 0, e = 0;
        f[s[0]]--;
        
        while(j < s.size()) {
            if(all(f)) {
                if(j-i+1 < mini) st = i, e = j; 
                mini = min(mini, j-i+1);
                
                f[s[i]]++;
                for(i = i+1; i < j && (h.find(s[i]) == h.end()); i++);
            } else {
                j++;
                if(h.find(s[j]) != h.end()) f[s[j]]--;
            }
        }
        if(mini == INT_MAX) return "";
        return s.substr(st, e-st+1);
    }
};
