class Solution {
    int *a;
    int num;
    int sum;
    vector<vector<string> > v;
    void nQueen(int t){
        if (t >= num){
            vector<string> v1;
            for(int i = 0; i < num; i++){
                string s;
                for (int j = 0; j < num; j++){
                    if (j == a[i])
                        s.push_back('Q');
                    else
                        s.push_back('.');
                }
                v1.push_back(s);
            }
            v.push_back(v1);   
        }
        else{
            for (int i = 0; i < num; i++){
                a[t] = i;
                if(isQueen(t))
                    nQueen(t+1);
            }
        }
    }
    
    bool isQueen(int n){
        for (int i = 0; i < n; i++){
            if(a[i] == a[n] || abs(a[i]-a[n]) == abs(i-n))
                return false;
        }
        return true;
    }
    
public:
    Solution(): a(0), num(0), sum(0){}
    vector<vector<string> > solveNQueens(int n) {
        num = n;
        a = new int[n];
        nQueen(0);
        return v;
    }
};
