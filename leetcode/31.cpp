class Solution {
public:
    void swap(vector<int>& v, int i, int k) { int x = v[i]; v[i] = v[k]; v[k] = x; }
    
    void nextPermutation(vector<int>& nums) {
        int k = nums.size()-1, l = nums.size()-1;
        while(k > 0 && nums[k] <= nums[k-1]) k--;
        while(k > 0 && nums[l] <= nums[k-1]) l--;
        
        if(k > 0) swap(nums, k-1, l);
        sort(nums.begin() + k, nums.end());
    }
};
