class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        
        int prev = 0, curr = 0, aux;        
        for(int i = 0; i < nums.size(); i++) {
            aux = curr;
            curr = max(nums[i] + prev, curr);
            prev = aux;
        }
        return max(prev, curr);
    }
};
