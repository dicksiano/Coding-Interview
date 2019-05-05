class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN, j;
        
        // Find min val and max val in the wrong place
        for(int i = 0; i < nums.size()-1; i = j) {
            for(j = i+1; j < nums.size()-1 && nums[i] == nums[j]; ) j++;
            for(; j < nums.size()-1 && nums[i] > nums[j] && nums[j] == nums[j+1]; ) j++;
            if(nums[i] > nums[j]) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[i]);
            }
        }
        
        // Find correct positions to min and max values
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > mini) { mini = i; break; }
        for(int i = nums.size()-1; i >= 0; i--)
            if(nums[i] < maxi) { maxi = i; break; }
        
        return (mini > maxi) ? 0 : maxi - mini + 1;
    } 
};
