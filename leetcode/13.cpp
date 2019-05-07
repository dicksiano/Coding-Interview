class Solution {
public:
    int romanToInt(string A) {
        if(A.size() == 0) return 0;

        unordered_map<char, int > m({ 
            {'I',1}, 
            {'V',5}, 
            {'X',10},   
            {'L',50},
            {'C',100}, 
            {'D',500}, 
            {'M',1000} });

        int sol = 0;
        for(int i = 0; i < A.size()-1; i++) {
            if(m[ A[i] ] < m[ A[i+1] ] ) sol -= m[ A[i] ];
            else sol += m[ A[i] ];
        }
        sol += m[ A[A.size()-1] ];
        return sol;
    }
};
