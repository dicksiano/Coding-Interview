
const string lessThan20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine", "Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
const string lessThan100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

const string biggerThan100[] = {" Hundred", " Thousand", " Million", " Billion"};

class Solution {
public:
    
    int rest(int n, int base) {
        return n - base * (n / base);
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        else return n2w(num).substr(1);
    }
    
    string n2w(int n) {
        if(n >= 1000000000)   return n2w(n / 1000000000) + biggerThan100[3] + n2w(rest(n, 1000000000));
        else if(n >= 1000000) return n2w(n / 1000000) + biggerThan100[2] + n2w(rest(n, 1000000));
        else if(n >= 1000)    return n2w(n / 1000) + biggerThan100[1] + n2w(rest(n, 1000));
        else if(n >= 100)     return n2w(n / 100) + biggerThan100[0] + n2w(rest(n, 100));
        else if(n >= 20)      return string(" ") + lessThan100[n / 10 - 2] + n2w(rest(n, 10));
        else if(n >= 1)       return string(" ") + lessThan20[n - 1];
        else return "";
    }
};
