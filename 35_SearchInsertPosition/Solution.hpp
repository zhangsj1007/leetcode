class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for(int i = 0; i < n; i++){
            if (A[i] < target){
                continue;
            }else{
                return i;
            }
        }
        
        return n;
    }
};
