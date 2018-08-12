class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return 0;
        int rows = board.size();
        int columns = board[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if (board[i][j] == 'X' && ((i == 0 || board[i-1][j] != 'X') && (j == 0 || board[i][j-1] != 'X')))
                    count++;
            }
        }
        return count;
    }
};
