class Solution {
public:
    int getSum(int a, int b) {
        size_t n = sizeof(int) * 8;
        bitset<32> aset(a), bset(b), cset;
        int carry = 0;
        
        // bitset count bits starting from right to left.
        for (int i = 0; i < n; ++i) {
            if (aset[i] == 0) {
                if (bset[i] == 0) {
                    cset[i] = carry;
                    carry = 0;
                } else if (carry == 0) {
                    cset[i] = 1;
                } else { // carry == 1.
                    cset[i] = 0;
                }
            } else { // aset[i] == 1.
                if (bset[i] == 0) {
                    if (carry == 0) {
                        cset[i] = 1;
                    } else { // carry == 1.
                        cset[i] = 0;
                    }
                } else { // bset[i] == 1.
                    if (carry == 0) {
                        cset[i] = 0;
                        carry = 1;
                    } else { // carry == 1.
                        cset[i] = 1;
                    }
                }
            }
        }
        
        return (int)(cset.to_ulong());
    }
};
