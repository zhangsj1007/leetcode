class Solution {
public:
    bool isPowerOfTwo(int n) {
        //From the method that if a num is the power of 2, it contains only 1 "1" in his bits
        if (n <= 0) return false;
        //== or != is prior to &
        return (n & (n-1)) == 0; 
    }
};
