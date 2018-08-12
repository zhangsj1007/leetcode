class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hWeight = 0;
        int i = 1;
        int j;
        for (j= 0; j <= 31; j++){
            if(n & i){
                hWeight++;
            }
            i <<= 1;
        }
    return hWeight;
    }
};
