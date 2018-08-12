class Solution {
public:
    int numSquares(int n) {
        //用于存储从0-n的数最少需要几个元素
        int dp[n+1];
        for(int i = 0; i <= n; i++){
            //最差的情况下，i由n个1组成
            dp[i] = i;
            //能否i用之前计算过的数再加上个j平方来代替
            for(int j = 1; i - j * j >= 0; j++){
                if (dp[i - j * j] + 1 < dp[i])
                    //这里面的加1实际上就是那个j的平方
                    dp[i] = dp[i - j * j] + 1;
            }
        }
        return dp[n];
    }
};
