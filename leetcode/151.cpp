class Solution {
public:
    void swap(string &s, int i, int j) { char tmp = s[i]; s[i] = s[j]; s[j] = tmp;}

    void rev(string &s, int i, int j) {
        while(i < j) swap(s, i++, j--);
    }
    
    void parse(string &s) {        
        while(s.size() > 0 && s[0] == ' ') s.erase(s.begin()); // Remove spaces in the beggin
        while(s.size() > 0 && s[ (int)s.size() - 1 ] == ' ') s.erase(s.begin() + s.size() - 1); // Remove spaces in the end

        for(int i = 0; i < (int)s.size()-1; i++) // Remove multiple spaces
            while(s[i] == ' ' && s[i+1] == ' ') s.erase(s.begin()+i);
    }
    string reverseWords(string s) {
        parse(s);

        for(int i = 0, j = 0; i < (int)s.size(); i = j+1) {
            for(j = i; j < (int)s.size() && s[j] != ' '; j++);
            rev(s, i, j-1);
        } 
        rev(s, 0, s.size()-1);
        return s;
    }

};
