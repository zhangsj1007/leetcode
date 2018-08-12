class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        // vector<vector <int>> dp;
        // for (int i = 0; i < n1 + 1; i++){
        //     vector<int> v(n2+1, 0);
        //     dp.push_back(v);
        // }
        vector<vector<int>> dp (n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++){
            for (int j = 0; j < n2; j++){
                if (word1[i] == word2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];
    }
};
