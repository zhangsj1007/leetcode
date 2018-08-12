class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<int> >v;
        vector<int> vInt;
        vector<vector<int> >::iterator iter = matrix.begin();
        int n = 0;
        for (; iter != matrix.end(); iter++){
            n++;
        }
        for (int i = 0; i < n; i++){
            vInt.clear();
            for (int j = n - 1; j >= 0 ; j--){
                vInt.push_back(matrix[j][i]);
            }
            v.push_back(vInt);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = v[i][j];
            }
        }
    }
};
