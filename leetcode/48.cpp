class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size()-1;
        for(int layer = 0; layer < (n+1)/2; layer++) 
            for(int i = layer; i < n-layer; i++) {
                int aux = matrix[layer][i];
                
                matrix[layer][i] = matrix[n-i][layer];
                matrix[n-i][layer] = matrix[n-layer][n-i];
                matrix[n-layer][n-i] = matrix[i][n-layer];
                matrix[i][n-layer] = aux;
            }
    }
};
