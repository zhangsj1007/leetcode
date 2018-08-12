class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        vector<vector<int> >res;
        vector<int> temp;
        for(int i = 1; i < 10; i++) a.push_back(i);
        calculate(k, n, a, a.begin(), res, temp);
        return res;
        
    }
    
    void calculate(int k, int n, vector<int>& a, vector<int>::iterator it, vector<vector<int> >& res, vector<int>& temp){
        if (k < 0)
            return;
        if (k == 0 && n == 0){
            res.push_back(temp);
        }
        for(auto p = it; p != a.end(); p++){
            if (*p <= n){
                temp.push_back(*p);
                calculate(k-1, n-*p, a, p+1, res, temp);
                temp.pop_back();
            }
        }
    }
};
