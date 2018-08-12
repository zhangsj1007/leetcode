class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        if (n == 0)
            return v;
        v.push_back(1);
        if (n == 1)
            return v;
        int i, j;
        int m;
        vector<vector<int> > vV;
        vV.push_back(v);
        for (i = 1; i < n; i++){
            m = 1 << i;
            v.clear();
            for (j = 0; j < vV[i-1].size(); j++)
                v.push_back(vV[i-1][j]);
            for (j = vV[i-1].size() - 1; j >= 0; j--)
                v.push_back(vV[i-1][j] + m);
            vV.push_back(v);
        }
        return vV[n-1];
    }
};
