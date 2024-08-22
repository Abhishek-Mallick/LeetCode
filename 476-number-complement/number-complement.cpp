class Solution {
public:
    int findComplement(int num) {
        // number of bits
        int num_bits = (int)(log2(num)) + 1;

        for(int i=0;i<num_bits;i++) {
            num = num ^ (1 << i);
        }
        return num;
    }
};