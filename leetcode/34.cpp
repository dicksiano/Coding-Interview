class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {  
        int i = 0, j = nums.size(), mid, s;
        
        // Lower-bound
        while(i < j) {
            mid = (i+j)/2;
            if(target <= nums[mid]) j = mid;
            else i = mid+1;
        }
        
        s = i; j = nums.size();
        
        // Upper-bound
        while(i < j) {
            mid = (i+j)/2;
            if(target < nums[mid]) j = mid;
            else i = mid+1;
        }
        
        return (s == i) ? vector<int>{-1, -1} : vector<int>{s, i-1};
    }
};
