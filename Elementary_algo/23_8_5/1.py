class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int i = 0;
        while(i < 32){
            res = res * 2 + n % 2;
            n /= 2;
            i++;
        }
        return res;
    }
};