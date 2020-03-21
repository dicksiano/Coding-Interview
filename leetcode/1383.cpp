class Solution {
    int MOD = 1000000007;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {  
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        vector<vector<long long> > m;
        for(int i = 0; i < speed.size(); i++) m.push_back( {speed[i], efficiency[i]} );
        
        auto f2 = [](vector<long long> &a, vector<long long> &b) { return (a[1] == b[1]) ? (a[0] > b[0]) : (a[1] > b[1]); };
        sort(m.begin(), m.end(), f2);
        
        long long sum = 0, maxi = 0;
        for(int i = 0; i < m.size(); i++) { 
            sum += m[i][0];
            pq.push(m[i][0]);
            
            if(pq.size() > k) sum -= pq.top(), pq.pop();
            
            maxi = max(maxi, sum * m[i][1]);
        }
        return maxi % MOD;
    }
};
