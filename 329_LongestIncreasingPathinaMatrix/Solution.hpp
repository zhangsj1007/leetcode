class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        makeDirections();
        int max = 1;
        int len;
        int rows = matrix.size();
        if (rows == 0)
            return 0;
            
        int columns = matrix[0].size();
        if (columns == 0)
            return 0;
        
        for (int i = 0; i < rows; i++){
            vector<int> v(columns, 0);
            memo_.push_back(v);
        }
        
        for (int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
               len = dfs(matrix, i, j, rows, columns);
               max = std::max(len, max);
            }
        }
        return max;
    }
    
    int dfs(vector<vector<int> >& matrix, int i, int j, int rows, int columns){
        if (memo_[i][j] != 0){
            return memo_[i][j];
        }
        int max = 1;
        for (auto dir : directions_){
            int row = i + dir.first;
            int column = j + dir.second;
            if (row < 0 || column < 0 || row >= rows || column >= columns || matrix[row][column] <= matrix[i][j])
                continue;
            int len = dfs(matrix, row, column , rows, columns) + 1;
            max = std::max(max, len);
        }
        memo_[i][j] = max;
        return max;
    }
    
private:
    void makeDirections(){
        //left
        directions_.push_back(make_pair(-1, 0));
        //right
        directions_.push_back(make_pair(1, 0));
        //down
        directions_.push_back(make_pair(0, -1));
        //up
        directions_.push_back(make_pair(0, 1));
    }
    
private:
    vector<pair<int, int> > directions_;
    vector<vector<int> > memo_;
};
