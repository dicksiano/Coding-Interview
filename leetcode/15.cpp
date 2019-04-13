class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > sol;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < (int)nums.size()-2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int s = i + 1, e = nums.size()-1;    
                while(s < e ) {
                    if(nums[i] + nums[s] + nums[e] == 0) {
                        sol.push_back(vector<int>{ nums[i], nums[s], nums[e] });
                        while (s < e && nums[s] == nums[s+1]) s++;
                        while (s < e && nums[e] == nums[e-1]) e--;
                        s++; e--;
                    }
                    else if(nums[i] + nums[s] + nums[e] < 0) s++;
                    else e--;
                }
            }
        }
        return sol;
    }
};
