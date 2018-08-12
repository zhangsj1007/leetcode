class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (n == 0)
            return 0;
        int ret = 0;
        unsigned int mask = 0x80000000;
        while(!(n&mask))
            mask >>= 1;
        while(mask){
            if ((m&mask) == (n&mask)){
                ret |= (m & mask);
            }else{
                break;
            }
            mask >>= 1;
        }
        return ret;
    }
};
