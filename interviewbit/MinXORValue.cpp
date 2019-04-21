

    int Solution::findMinXor(vector<int> &A) {
        sort(A.begin(), A.end());
        int mini = INT_MAX;
        for(int i = 0; i < A.size()-1; i++)
            mini = min(mini, A[i] ^ A[i+1]);
        return mini;
    }

