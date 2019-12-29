class Solution {
public:
    //this method is superior to methed of sorting first, O
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int size = A.size();
        res.resize(size);
        int cnt = size - 1;
        for (int i = 0, j = size - 1; i <= j;) {
            if (abs(A[i]) >= abs(A[j])) {
                res[cnt] = pow(A[i], 2);
                i += 1;
            } else {
                res[cnt] = pow(A[j], 2);
                j -= 1;
            }
            cnt -= 1;
        }
        
        return res;
    }
};
