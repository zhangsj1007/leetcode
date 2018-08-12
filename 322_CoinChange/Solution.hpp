class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return -1;
        if (amount == 0) 
            return 0;
        int dp[amount + 1];
        dp[0] = 0;
        for (int amt = 1; amt <= amount; amt++){
            dp[amt] = -1;
            for (auto coin : coins){
                if (amt - coin >= 0 && dp[amt-coin] != -1){
                    if (dp[amt] == -1)
                        dp[amt] = dp[amt-coin] + 1;
                    else
                        dp[amt] = min(dp[amt-coin] + 1, dp[amt]);
                }
            }
        }
        return dp[amount];
    }
};
