class Solution {
public:
    int climbStairs(int n) {
        int result1[3] = {0, 1, 2};
        if (n <= 2)
            return result1[n];
        int result2;
        int step1 = 2;
        int step2 = 1;
        for (int i = 3; i <= n; i++){
            result2 = step1 + step2;
            step2 = step1;
            step1 = result2;
        }
        return result2;
        
    }
};
