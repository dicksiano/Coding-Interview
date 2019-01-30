class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0 || x == 1.0) return x;
        if(n < 0) return myPow(1.0/x , -(n+1))/x; // OVERFLOW: -1 * MIN_INT = MIN_INT
        
        double res = 1.0;
        while(n) {
            if(n%2) { res *= x; n--; }
            else { x *= x; n /= 2; }
        }
        return res;
    }
};
