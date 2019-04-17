class Solution {
public:    
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        if(s.size() < 2) return 1;
        
        int a = 1, b = 1, aux;
        for(int i = s.size()-1; i >= 0 ; i--) {
            aux = a;
            
            if(s[i] == '0') a = 0;
            else if(i <s.size()-1)
                if(s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))  a = a + b;
                        
            b = aux;
        }
        return a;
    }
};
