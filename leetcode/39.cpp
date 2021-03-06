class Solution {
public:
    void backtrack(vector<vector<int> > &sol, vector<int>& aux, vector<int>& v, int x, int start) {
        if(x == 0) {
            sol.push_back(aux);
            return;
        }
        
        for(int i = start; i < v.size() && v[i] <= x; i++) {
            aux.push_back(v[i]);
            backtrack(sol, aux, v, x - v[i], i);
            aux.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > sol;
        vector<int> aux;
        
        sort(candidates.begin(), candidates.end());
        backtrack(sol, aux, candidates, target, 0);
        return sol;
    }
};
