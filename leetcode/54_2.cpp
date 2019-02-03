class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<int>();
        
        int total = matrix.size() * matrix[0].size(), m = matrix.size(), n = matrix[0].size();
        int layer = 0, curr = 0;
        
        vector<int> res;
        
        while(curr < total) {
            for(int i = layer; i < n-layer-1; i++) 
                if(curr < total) {res.push_back(matrix[layer][i]); curr++; }
            
            for(int i = layer; i < m-layer-1; i++)
                if(curr < total) {res.push_back(matrix[i][n-layer-1]); curr++; }
            
            for(int i = n-layer-1; i > layer; i--)
                if(curr < total) {res.push_back(matrix[m-layer-1][i]); curr++; }
            
            for(int i = m-layer-1; i > layer; i--)
                if(curr < total) {res.push_back(matrix[i][layer]); curr++; }
            
            if(m == n && m%2 && curr == total-1) {res.push_back(matrix[m/2][n/2]); curr++; }
            layer++;
        }
        return res;
    }
};
