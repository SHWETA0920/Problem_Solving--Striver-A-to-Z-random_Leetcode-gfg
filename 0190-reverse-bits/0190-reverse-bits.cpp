class Solution {
public:
    int reverseBits(int n) {
        bitset<32> binary(n);
        unsigned int result = binary.to_ulong();

        unsigned int ans = 0;

        for (int i = 0; i < 32; i++) {        
            int bit = n & 1;
            ans = (ans << 1) | bit;
            n = n >> 1;
        }

        return ans;
    }
};