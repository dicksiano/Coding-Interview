vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        for(int i = 0;;i++) {
            if(ht.find(target - nums[i]) != ht.end()) return vector<int> {ht[ target - nums[i] ], i};
            ht[nums[i]] = i;
        }
}
