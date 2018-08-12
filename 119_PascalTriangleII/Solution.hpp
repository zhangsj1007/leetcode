class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        vector<vector<int> >vV;
        int i, j;
        
        v.push_back(1);
        if (rowIndex == 0){
            return v;
        }
        
        vV.push_back(v);
        
        for(i = 1; i <= rowIndex; i++){
            v.clear();
            for(int j = 1; j <= i + 1; j++){
                if (j == 1){
                    v.push_back(1);
                }else if (j == i + 1){
                    v.push_back(1);
                }else{
                    int t = vV[i - 1][j - 2] + vV[i - 1][j - 1];
                    v.push_back(t);
                }
            }
            vV.push_back(v);
        }
        return vV[rowIndex];
    }
};
