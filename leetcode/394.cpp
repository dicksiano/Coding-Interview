class Solution {
public:
    string mult(const string& s, unsigned int n) {
        stringstream out;
        while (n--) out << s;
        return out.str();
    }
    
    string d(string s, unordered_map<int, int> m, int i, int j) {
        stringstream res;
        
        for(int k = i; k <= j;)  {            
            if(isalpha(s[k])) res << s[k++];               
            else if(isdigit(s[k])) {
                int n = 0;
                while(isdigit(s[k])) n = 10 * n + (s[k++] - '0');
                res << mult(d(s, m, k+1, m[k]-1), n);
                k = m[k] + 1;
            }
        }
        return res.str();
    }
    
    unordered_map<int, int> preprocess(string s) {
        unordered_map<int, int> m;
        stack<int> p;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '[') p.push(i);
            else if(s[i] == ']') m[ p.top() ] = i, p.pop();
        }
        return m;
    }
    
    string decodeString(string s) {
        unordered_map<int, int> m = preprocess(s);
        return d(s, m, 0, s.size()-1);
    }
};
