vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > sol( 2*(A.size()-1) + 1 );
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A.size(); j++)
            sol[i+j].push_back(A[i][j]);
    return sol;
}
