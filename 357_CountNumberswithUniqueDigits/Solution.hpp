class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        vector<int> f(11, 0);
        for(int i = 1; i <= 10; i++){
            if (i == 1) f[i] = 10;
            else if (i == 2) f[i] = 81;
            else{
                f[i] = f[i-1] * (9 - i + 2);
            }
        }
        vector<int> r(11, 0);
        for (int i = 1; i <= 10; i++){
            r[i] = r[i-1] + f[i];
        }
        if (n < 10 ) return r[n];
        else return r[10];
    }
};
