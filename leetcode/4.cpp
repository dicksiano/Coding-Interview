class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size() + nums2.size()) / 2;
        int i = -1, j = -1;
        while(i + 1 + j + 1 < mid) {
            if(i == nums1.size()-1) j++;
            else if(j == nums2.size()-1) i++;
            else if(nums1[i+1] < nums2[j+1]) i++;
            else j++;
        }
        
        if( (nums1.size() + nums2.size()) % 2) 
            return min( i+1 < nums1.size() ? nums1[i+1] : INT_MAX,
                        j+1 < nums2.size() ? nums2[j+1] : INT_MAX );
        
        int a = max( i >= 0 ? nums1[i] : INT_MIN,
                     j >= 0 ? nums2[j] : INT_MIN );
        int b = min( i+1 < nums1.size() ? nums1[i+1] : INT_MAX,
                     j+1 < nums2.size() ? nums2[j+1] : INT_MAX );
        return 0.5 * ( a + b );  
    }
}; 
