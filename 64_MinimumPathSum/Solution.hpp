class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int lines, cols;
        lines = grid.size();
        cols = grid[0].size();
        
        for (int i = 0; i < lines; i++){
            for(int j = 0; j < cols; j++){
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    grid[i][j] += grid[i][j-1];
                else if (j == 0)
                    grid[i][j] += grid[i-1][j];
                else
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[lines-1][cols-1];
    }
};
