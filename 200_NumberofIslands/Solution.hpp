class Solution {
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0){
            return 0;
        }
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        //vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n ; j++){
                if (grid[i][j] == '1'){
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j){
        if (grid[i][j] == '2'){
            return ;
        }
        if ((int)grid[i][j] == '1'){
            grid[i][j] = '2';
            for (auto dir : directions){
                int i1 = i + dir[0];
                int j1 = j + dir[1];
                if (i1 < 0 || i1 >= m || j1 < 0 || j1 >= n || grid[i1][j1] == '0'){
                    continue;
                }
                bfs(grid, i1, j1);
            }
        }
    }
private:
    int m;
    int n;

};
