class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        vector<vector<int> > vV;
        vector<int> temp;
        for(int i = 0; i < n; i++)
            v.push_back(i+1);
        calculate(v, 0, k, vV, temp);
        return vV;
    }
    
    void calculate(vector<int>& v, int m, int k, vector<vector<int> >& vV, vector<int>& temp){
        if (k == 0){
            vV.push_back(temp);
            return;
        }
        for (int i = m; i < v.size(); i++){
            temp.push_back(v[i]);
            calculate(v, i+1, k-1, vV, temp);
            temp.pop_back();
        }
        
    }
};
