class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l(nums.size(), 1), r(nums.size(), 1);
        
        l[0] = nums[0]; 
        r[nums.size() -1] = nums[nums.size() -1]; 
        
        for(int i = 1; i < nums.size(); i++) l[i] = nums[i] * l[i-1];
        for(int i = nums.size()-2; i >= 0; i--) r[i] = nums[i] * r[i+1];
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = (i > 0)  ? l[i-1] : 1;
            if(i < nums.size()-1) nums[i] *= r[i+1];
        }
        return nums;
    }
};
