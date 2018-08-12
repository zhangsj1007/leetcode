class Solution {
public:
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0){
            return false;
        }
        int n = board[0].size();
        if (n == 0){
            return false;
        }
        vector<vector<bool>> record(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfsSearch(board, record, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfsSearch(vector<vector<char>> &board, vector<vector<bool>>& record, string &word, int v, int h, int i){
        int m = board.size();
        int n = board[0].size();
        if (record[v][h] == true){
            return false;
        }
        if (board[v][h] != word[i]){
            return false;
        }
        if (word.size() == i + 1){
            return true;
        }
        record[v][h] = true;
        for (auto &dir : directions){
            int x = v + dir[0];
            int y = h + dir[1];
            if (x >= m || x < 0 || y >= n || y < 0){
                continue;
            }
            if (dfsSearch(board, record, word, x, y, i + 1)){
                return true;
            }
        }
        record[v][h] = false;
        return false;
    }
};
