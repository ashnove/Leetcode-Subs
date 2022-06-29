class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        int idx = 31;
        for(int i = 0; i < 32; i++){
            rev += (1 << idx) * ((1 << i) & n ? 1 : 0);
            idx--;
        }
        return rev;
    }
};