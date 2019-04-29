class Solution {
public:
    int largestRectangleArea(vector<int> heights) {
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
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0) return 0;
        vector<vector<int> > m(matrix.size(), vector<int>(matrix[0].size(),0));
        
        for(int i = 0; i < matrix[0].size(); i++) 
            m[0][i] = matrix[0][i] - '0'; 
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                m[i][j] += (matrix[i][j] == '1') ? m[i-1][j] + 1: 0;
                        
        int maxi = 0;
        for(int i = 0; i < matrix.size(); i++)
            maxi = max(maxi, largestRectangleArea(m[i]));
        return maxi;
    }
};
