class Solution {
public:
    int bs(vector<int> &v, int i, int j) {
        if(v[i] <= v[j]) return v[i];
        if(i + 1 == j) return min(v[i],v[j]);
        
        int mid = (i+j)/2;
        if(v[i] > v[mid]) return bs(v,i+1,j);
        return bs(v, mid, j);
    }
    
    int findMin(vector<int>& nums) {
        int N = (int) nums.size() - 1;
        if(N < 0) return 0;
        
        return bs(nums, 0, N);        
    }
};
