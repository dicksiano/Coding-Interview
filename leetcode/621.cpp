class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {        
        int res = 0, maxi = 0;
        vector<int> f(26, 0);
        
        for(char c : tasks) 
            maxi = max(maxi, ++f[c - 'A']);
        
        res = (maxi - 1) * (n + 1);
        
        for(int freq : f) 
            if(maxi == freq) res++;
        return max(res, (int)tasks.size());
    }
};
