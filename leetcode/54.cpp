/*
    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*/
vector<int> spiralOrder(vector<vector<int> > &A) {
    int m = A.size() -1, n = A[0].size()-1, layer = 0;
    int total = (m+1) * (n+1);
    vector<int> res;
    while( res.size() < total ) {
        for(int k =     layer; k < n - layer; k++) 
            if(res.size() < total) res.push_back(A[layer][k]);
        for(int k =     layer; k < m - layer; k++) 
            if(res.size() < total) res.push_back(A[k][n -layer]);
        for(int k = n - layer; k >     layer; k--)
            if(res.size() < total) res.push_back(A[m - layer][k]);  
        for(int k = m - layer; k >     layer; k--) 
            if(res.size() < total) res.push_back(A[k][layer]); 
        
        if((m == n) && (m%2 == 0) && res.size() == total-1) res.push_back(A[m/2][m/2]);
        layer++;
    }
    return res;
}