class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size1, size2, i , j;
        size1 = matrix.size();
        size2 = matrix[0].size();
        /* not very elegant， 两层循环，o（m*n）
        for (i = 0; i < size1;){
            for (j = size2 - 1; j >= 0;){
                if (matrix[i][j] < target){
                    i++;
                    break;
                }else if (matrix[i][j] > target){
                    j--;
                    continue;
                }
                else 
                    return true;
            }
           if (j < 0)
                i++;
        }
        return false;*/
        //代码更加简练，一层循环。o（m+n）
        if (size1 == 0 || size2 == 0)
            return false;
        i = 0;
        j = size2 - 1;
        while(i < size1 && j >= 0){
            if (matrix[i][j] > target) j--;
            else if(matrix[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};
