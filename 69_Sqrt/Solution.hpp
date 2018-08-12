class Solution {
public:
    int mySqrt(int x) {
        //long long v = x;
        //while(v * v > x){
        //    v = (v + x / v) >> 2;
        //}
        //return v;
        long long v = x;  

        while(v * v > x)
            v = (v + (x / v)) >> 1;

        return v; 
        
    }
};
