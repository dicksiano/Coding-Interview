class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        
        stack<int> s;
        int maxi = 0, h;
        for(int i = 0; i < heights.size(); ) {
            if(s.empty() || heights[i] > heights[ s.top() ]) {
                s.push( i++ );
            } else {
                h = s.top(); s.pop();
                maxi = max(maxi, heights[h] * ( s.empty() ? i : i-1-s.top() ));
            }
        }
        return maxi;
    }
};
