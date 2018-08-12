class Solution {
public:
    int getSum(int a, int b) {
        bool carry = false;
        int result = 0;
        int ta = 1;
        int tb = 1;
        for (int i = 0; i < 32; i++){
            ta <<= i;
            tb <<= i;
            //== 优先级高于按位运算
            if (((ta & a) == 0) && ((tb & b) == 0)){
                if (carry){
                    set1(i, result);
                }else{
                    set0(i, result);
                } 
                carry = false;
            }else if(((ta & a) != 0) && ((tb & b) != 0)){
                if (carry){
                    set1(i, result);
                }else{
                    set0(i, result);
                }
                carry = true;
            }else{
                if (carry){
                    set0(i, result);
                    carry = true;
                }else{
                    set1(i, result);
                    carry = false;
                }
            }
            
            ta = 1;
            tb = 1;
        }
        return result;
    }
    
    void set1(int n, int & value){
        int t = 1;
        t <<= n;
        value |= t;
    }
    
    void set0(int n, int & value){
        int t = 1;
        t <<= n;
        t = ~t;
        value &= t; 
    }
};
