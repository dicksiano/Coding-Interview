class Solution {
public:
    void backtrack(vector<vector<int> > &sol, vector<int>& aux, vector<int>& v, int x, int k, int start) {
        if(aux.size() == k) {
            if(x == 0) sol.push_back(aux);
            return;
        }
        
        for(int i = start; i < v.size() && v[i] <= x; i++) {
            aux.push_back(v[i]);
            backtrack(sol, aux, v, x - v[i], k, i+1);
            aux.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > sol;
        vector<int> aux;
        
        vector<int> v{1,2,3,4,5,6,7,8,9};
        backtrack(sol, aux, v, n, k, 0);
        return sol;        
    }
};
