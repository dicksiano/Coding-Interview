class Solution {
public:    
    int rbs(vector<int> &v, int x, int i, int j) {
        if(i == j && v[i] == x) return i;
        if(i >= j) return -1;
        if(i+1 == j) {
            if(v[i] == x) return i;
            if(v[j] == x) return j;
            return -1;
        }
        
        int mid = (i+j)/2;     
        if(v[mid] == x) return mid;
        
        if(v[i] < v[mid]) {
            if(v[i] <= x && x < v[mid]) return rbs(v,x,i,mid-1);
            else return rbs(v,x,mid+1,j);
        } else {
            if(x > v[mid] && x <= v[j]) return rbs(v,x,mid+1,j);
            else return rbs(v,x,i,mid-1);
        }
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        return rbs(nums, target, 0, nums.size()-1);
    }
};
