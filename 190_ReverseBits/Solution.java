public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int m1 = 1;
        int m2 = 1 << 31;
        
        while((m1 >> 1) != m2){
            int R = n & m1;
            int L = n & m2;
            if ((R == 0 && L != 0) || (R != 0 && L == 0)){
                n ^= m1;
                n ^= m2;
            }
            m1 <<= 1;
            m2 >>>= 1;
        }
        return n;
    }
}
