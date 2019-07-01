class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && i - dq.back() >= k) dq.pop_back();
            while(!dq.empty() && nums[ dq.front() ] <= nums[i]) dq.pop_front(); 
            
            dq.push_front(i);
            if(i >= k-1) v.push_back( nums[ dq.back() ] );
        }
        return v;
    }
};
