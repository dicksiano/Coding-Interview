class Solution {
public:
    string intToRoman(int A) {
        unordered_map<int, string> m({ 
                {1,    "I"}, 
                {4,   "IV"}, 
                {5,    "V"}, 
                {9,   "IX"}, 
                {10,   "X"},   
                {40,  "XL"},  
                {50,   "L"},
                {90,  "XC"}, 
                {100,  "C"}, 
                {400, "CD"},  
                {500,  "D"},
                {900, "CM"},
                {1000, "M"} });

        vector<int> v{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        string sol = "";

        while(A) {
            if(A >= v[i]) A -= v[i], sol += m[ v[i] ];
            else i++; 
        }
        return sol;
    }
};
