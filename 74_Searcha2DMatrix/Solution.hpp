class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int line;
        int i;
        int j;
        
        row = matrix.size();
        line = matrix[0].size();
        i = 0;
        j = line - 1;
        while (i < row && j >= 0){
            if (matrix[i][j] > target) j--;
            else if (matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};
