class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[obstacleGrid.size()][obstacleGrid[0].size()];
        for (int i = 0 ; i < obstacleGrid.size(); i++){
            for (int j = 0; j < obstacleGrid[0].size(); j++){
                if (obstacleGrid[i][j] == 0){
                    if (i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if (i == 0)
                        dp[i][j] = dp[i][j-1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
    
};
