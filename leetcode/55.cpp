class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0; i < nums.size() && i <= maxi; i++)
            maxi = max(maxi, i + nums[i]);
        return maxi >= (nums.size()-1);
    }
};
