int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return 0;;
    
    int maxDiff = 0, minValue = 999999, maxValue = -999999;
    int gap = 0, bucket = 0, prev, numBucket;
    
    for(int i = 0; i < A.size(); i++) {
        minValue = min(minValue, A[i]);
        maxValue = max(maxValue, A[i]);
    }
    if(minValue == maxValue) return 0;
    
    gap = max(1, (int)((maxValue - minValue) / (A.size()-1)) );
    numBucket = 1 + (maxValue-minValue)/gap;
    
    vector<int> mini(numBucket, -1);
    vector<int> maxi(numBucket, -1);
    for(int i = 0; i < numBucket; i++) {
        bucket = (int)((A[i] - minValue)/gap);
        mini[bucket] = (mini[bucket] == -1) ? A[i] : min(A[i], mini[bucket]);
        maxi[bucket] = max(A[i], maxi[bucket]);
    }
    
    for(int i = 0; i < numBucket; i++) {
        if(mini[i] >= 0){
            maxDiff = max(maxDiff, mini[i]-prev);
            prev = maxi[i];
        }    
    }
    
return maxDiff;
}
