class Solution {
public:
    int singleNumber(int A[], int n) {
        int a[32] = {0};
        int i;
        int j;
        unsigned int num;
        
        for(i = 0; i < n; i++){
            num = 1;
            for(j = 0; j < 32; j++){
                num = 1;
                num <<= j;
                a[j] += (A[i] & num) >> j;
            }
        }
        
        for (i = 0; i < 32; i++){
            a[i] %= 3;
        }
        
        num = 0;
        
        for (i = 0; i < 32; i++){
            a[i] <<= i;
            num |= a[i];
        }
        
        return num;
    }
};
