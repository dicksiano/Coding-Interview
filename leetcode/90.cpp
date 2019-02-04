class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        
        vector<int> aux;
        vector< vector<int> > res;
        
        sub(nums, res, aux, 0);
        return res;
    }
private:
    void sub(vector<int> v, vector<vector<int>> &r, vector<int> aux, int s) {
        r.push_back(aux);
        
        for(int i = s; i < v.size(); i++) 
            if( i == s || v[i] != v[i-1]) {
                aux.push_back(v[i]);            
                sub(v, r, aux, i+1);
                aux.pop_back();
            }
    }
};
