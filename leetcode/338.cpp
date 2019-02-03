class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v; v.push_back(0);
        for(int i = 1; i <= num; i++) v.push_back(1 + v[i & (i-1)]);
        return v;
    }
};
