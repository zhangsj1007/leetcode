class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int columns = 0;
        int rows = 0;
        vector<int> columns0Vec;
        vector<int> rows0Vec;
        vector<vector<int> >::iterator iter1 = matrix.begin();
        while(iter1 != matrix.end()){
            rows++;
            iter1++;
        }
        vector<int>::iterator iter2 = matrix[0].begin();
        while(iter2 != matrix[0].end()){
            columns++;
            iter2++;
        }
        int column = 0;
        int row = 0;
        while(row < rows){
                while (column < columns){
                        if (matrix[row][column] == 0){
                            if (find(rows0Vec.begin(), rows0Vec.end(), row) == rows0Vec.end())
                                rows0Vec.push_back(row);
                            if (find(columns0Vec.begin(), columns0Vec.end(), column) == columns0Vec.end())
                                columns0Vec.push_back(column);
                        }
                        column++;
                }
                column = 0;
                row++;
        }
        
        vector<int>::iterator iter3 = rows0Vec.begin();
        vector<int>::iterator iter4 = columns0Vec.begin();
        int line = 0;
        for(; iter3 != rows0Vec.end(); iter3++){
            for(line = 0; line < columns; line++)
                matrix[*iter3][line] = 0;
        }
        for(; iter4 != columns0Vec.end(); iter4++){
            for(line = 0; line < rows; line++)
                matrix[line][*iter4] = 0;
        }
    }
};
