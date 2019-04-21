int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int i = 0, j = 0;
    while(i < A.size()-1 && A[i+1][j] <= B ) i++;
    while(j < A[0].size()-1 && A[i][j+1] <= B) j++;
    return (A[i][j] == B) ? 1 : 0;
}
