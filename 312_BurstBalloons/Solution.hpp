class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int nums2[nums.size() + 2] = {};
        int n = 1;
        for (int i : nums){
            nums2[n++] = i;
        }
        nums2[0] = 1;
        nums2[n++] = 1;
        
        int dp[n][n] = {};
        
        for (int k = 2; k < n; k++){
            for (int left = 0; left < n - k ; left++){
                int right = left + k;
                for (int i = left + 1; i < right; i++){
                    dp[left][right] = max(dp[left][right], nums2[left]*nums2[i]*nums2[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
