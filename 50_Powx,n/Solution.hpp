class Solution {
public:
    double pow(double x, int n) {
        int absn = n;
        if (n < 0){
            absn = -n;
        }
        if (n == 0){
            return 1;
        }
        int flag = 1;
        if (x < 0 && (n & 1 == 1)){
            flag = -1;
        }
        double absx = x;
        if (x < 0){
            absx = -x;
        }
        
        double result = 1.0;
        double result2 = 1.0;
        double result3 = 1.0;
        for (int i = 0 ; i < absn; i++){
            result *= absx;
            if (equal(result, result2)){
                break;
            }
            result2 = result;
        }
        if (n < 0){
            result = 1.0 / result;
        }
        if (flag < 0){
            result = -result;
        }
        return result;
    }
    bool equal(double a, double b){
        if (a - b > -0.00000000001 && a - b < 0.0000000001){
            return true;
        }
        else 
            return false;
    }
};
