class Solution {
public:
    const int MAX_NUM = 32;
    
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < MAX_NUM/2; i++) {
            uint32_t a = n & (1 << i);
            uint32_t b = n & (1 << (31-i));
            
            n = (a) ? (n | (1 << (31-i)) ) : (n & ~(1 << (31-i)) );
            n = (b) ? (n | (1 << i) )      : (n & ~(1 << i) ); 
        }    
        return n;
    }
};
