class Solution {
public:
    string h(vector<vector<char>>& m) {
        string s = "";
        for(int i = 0 ; i < m.size(); i++)
            for(int j = 0; j < m[0].size();j ++)
                s.push_back(m[i][j]);        
        return s;
    }
    
    int bt(string &s) {        
        if( dp.find(s) != dp.end() ) return dp[s];
        
        int a = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                if(s[j + i* M] == '.')  {
                    string S = s;
                    S[j + i* M] = '#';
                    a = max(a, bt(S) );
                    
                    if(j > 0) {
                        if(S[j-1 + (i) * M] == '.')              S[j-1 + (i) * M] = '1';
                        if(i < N-1 && S[j-1 + (i+1) * M] == '.') S[j-1 + (i+1) * M] = '1';
                    }
                    if(j < (M-1) ) {
                        if(S[j+1 + (i) * M] == '.')              S[j+1 + (i) * M] = '1';
                        if(i < N-1 && S[j+1 + (i+1) * M] == '.') S[j+1 + (i+1) * M] = '1';
                    }
                    S[j + i* M] = '1';
                    a = max(a, 1 + bt(S) );
                }
        return dp[ s ] = a;
    }
    int maxStudents(vector<vector<char>>& seats) {
        string s = "";
        for(int i = 0 ; i < seats.size(); i++)
            for(int j = 0; j < seats[0].size();j ++)
                s.push_back(seats[i][j]);  
        N = seats.size();
        M = seats[0].size();
        return bt(s);
    }
private:
    int N, M;
    unordered_map<string, int> dp;
};
