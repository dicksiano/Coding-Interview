class Solution {
public:
    int dp(vector<int>& v, int s, int e) {
       int prev = 0, curr = 0, aux;        
        for(int i = s; i <= e; i++) {
            aux = curr;
            curr = max(v[i] + prev, curr);
            prev = aux;
        }
        return max(prev, curr); 
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        if(nums.size() < 2) return nums[0];
        return max(dp(nums, 0, nums.size()-2), dp(nums, 1, nums.size()-1));
    }
};
