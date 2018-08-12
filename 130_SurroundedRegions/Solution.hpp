class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0){
            return;
        }
        n = board[0].size();
        for (int i = 0; i < n; i++){
            if (board[0][i] == 'O'){
                bfs(board, 0, i);
            }
            if (board[m-1][i] == 'O'){
                bfs(board, m-1, i);
            }
        }
        for (int i = 0; i < m; i++){
            if (board[i][0] == 'O'){
                bfs(board, i, 0);
            }
            if (board[i][n-1] == 'O'){
                bfs(board, i, n-1);
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'M'){
                    board[i][j] = 'O';
                }else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void bfs(vector<vector<char>>& board, int i, int j){
        queue<pair<int, int>> q;
        board[i][j] = 'M';
        q.push(make_pair(i, j));
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            pair<int, int> adjNodes[4] = {make_pair(node.first - 1, node.second), make_pair(node.first + 1, node.second), 
                                         make_pair(node.first, node.second - 1), make_pair(node.first, node.second + 1)};
            for (auto anode : adjNodes){
                if (anode.first >= 0 && anode.first < m && anode.second >= 0 && anode.second < n && board[anode.first][anode.second] == 'O'){
                    q.push(make_pair(anode.first, anode.second));
                    board[anode.first][anode.second] = 'M';
                }
            }
        }
    }
    int m;
    int n;
};
