int Solution::maxSpecialProduct(vector<int> &A) {
    stack<long long int> lStack, rStack;
    vector<long long int> l(A.size()), r(A.size());
    
    lStack.push(-1); lStack.push(0);
    rStack.push(-1); rStack.push(A.size() - 1);
    l[0] = -1; r[A.size() -1] = -1;
    
    for(int i = 1; i< A.size(); i++) {
        while(lStack.size() > 1 && A[ lStack.top() ] <= A[i]) lStack.pop();

        l[i] = lStack.top();
        lStack.push(i);
    }
    for(int i = A.size() - 2; i>= 0; i--) {
        while(rStack.size() > 1 && A[ rStack.top() ] <= A[i]) rStack.pop();

        r[i] = rStack.top();
        rStack.push(i);
    }
    
    long long int prod = 0;
    for(int i = 0; i< A.size(); i++) prod = max(prod, max( (long long int)0,l[i]) * r[i] );
    return prod%1000000007;
}

