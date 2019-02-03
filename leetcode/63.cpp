class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x <= 2) return 1;

        int l = 1, h = x/2, mid;
        while(1) {
            mid = (l + h) / 2;
            if(mid > x/mid) h = mid - 1;
            else {
                if( (mid+1) > x/(mid+1)) return mid;
                l = mid+1;
            }
        }
    }
};
