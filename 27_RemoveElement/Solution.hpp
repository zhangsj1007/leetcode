class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        vector<int> vInt;
        for (int i = 0; i < n; i++){
            if (elem != A[i]){
                vInt.push_back(A[i]);
            }
        }
        for(int i = 0; i < vInt.size(); i++){
            A[i] = vInt[i];
        }
        return vInt.size();
    }
};
