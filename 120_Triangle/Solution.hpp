class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> >dp;
        dp.push_back(triangle[0]);
        int k = 0;
        
        for(int j = 1 ; j < triangle.size(); j++){
            vector<int> v = triangle[j];
            vector<int> v1;
            vector<int> v2 = dp[k++];
            for(int i = 0; i < v.size(); i++){
                if (i == 0){
                    v1.push_back(v2[i] + v[i]);
                }else if (i == v.size() - 1){
                    v1.push_back(v2[i-1] + v[i]);
                }else{
                    v1.push_back(min(v2[i-1] + v[i], v2[i] + v[i]));
                }
            }
            dp.push_back(v1);
        }
        int mValue = dp[dp.size() - 1][0]; 
        for (int i : dp[dp.size() - 1]){
            if (i < mValue)
                mValue = i;
        }
        return mValue;
    }
};
