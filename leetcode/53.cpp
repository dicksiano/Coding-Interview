class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxElem = INT_MIN, maxSum = INT_MIN, curr = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxElem = max(maxElem, nums[i]);
            curr = (curr + nums[i] > 0) ? (curr + nums[i]) : 0;
            maxSum = max(maxSum, curr);
        }
        return (maxSum == 0) ? maxElem : maxSum;
    }
};
