class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (grid[i][j] == 0) continue;
                else{
                    if (i == 0 || grid[i-1][j] == 0) 
                        perimeter++;
                    if (i == rows-1 || grid[i+1][j] == 0)
                        perimeter++;
                    if (j == 0 || grid[i][j-1] == 0)
                        perimeter++;
                    if (j == columns-1 || grid[i][j+1] == 0)
                        perimeter++;
                }
            }
        }
        return perimeter;
    }
};
