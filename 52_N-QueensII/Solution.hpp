class Solution {
    int *a;
    int num;
    int sum;
public:
    Solution(): a(0), num(0), sum(0){}
    int totalNQueens(int n) {
        num = n;
        a = new int[n];
        nQueen(0);
        return sum;
    }
    
    void nQueen(int t){
        if (t >= num)
            sum++;
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
};
