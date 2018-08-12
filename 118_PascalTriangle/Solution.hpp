/*这个算法就是2个容器一个装vector<int>的vecV, 一个装int的vecI，不断算出每个vecI，将他添加到vecV中
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vecV;
        vector<int> vecI;
        if (numRows == 0)
            return vecV;
        for (int i = 1; i <= numRows; i++){
            for(int j = 0; j < i; j++){
                if(i == 1){
                    vecI.push_back(1);
                }else{
                    if(j == 0 || j == i-1){
                        vecI.push_back(1);
                    }else{
                        vecI.push_back(vecV[i-2][j-1] + vecV[i-2][j]);  //这里应该是i-2；
                    }
                }
            }
            vecV.push_back(vecI);
           vecI.clear();
        }
        return vecV;
    }
};
