class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bitset<200 * 100 + 1> bitmask(1);
        
        for(int x : nums) bitmask |= bitmask << x;
        
        return (sum%2 == 0) && bitmask[sum/2];
    }
};
