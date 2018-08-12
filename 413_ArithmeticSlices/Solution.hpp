class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int ret = 0, count = 0;
        for (int i = 1; i < A.size() - 1; i++){
            if (A[i] - A[i-1] == A[i+1] - A[i]){
                ret += ++count;
            }else count = 0;
        }
        return ret;
    }
};
