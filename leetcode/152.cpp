class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int minProd = 1;
        int maxProd = 1;
        int sol = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++, sol = max(sol, maxProd)) {
            if(nums[i] < 0) swap(minProd, maxProd);
            
            minProd = min(nums[i], minProd*nums[i]);
            maxProd = max(nums[i], maxProd*nums[i]);
        }
        return sol;
    }
};
