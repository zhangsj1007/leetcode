class Solution {
public:
    vector<int> ret;
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i <= 9; i++){
            depthSearch(i, n);
        }
        return ret;
    }
    
    void depthSearch(int p, int n){
        if (p <= n)
            ret.push_back(p);
        for(int i = 0; i <= 9; i++){
            int temp = p * 10 + i;
            if(temp <= n)
                depthSearch(temp, n);
            else 
                return;
        }
    }
};
