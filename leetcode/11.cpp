class Solution {
public:
    int maxArea(vector<int>& height) {        
        int res = 0, i = 0, j = height.size()-1, w, h;
        
        while(i < j) {
            w= j-i;
            h = height[i] < height[j] ? height[i++] : height[j--];
            res = max(res, w * h);
        }
        return res;
    }
};
