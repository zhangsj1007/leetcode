class Solution {
public:
    int maxSubArray(int A[], int n){
        int sum = 0x80000000;
        int curSum = -1;
        
        for (int i = 0; i < n; i++){
            if (curSum < 0){
                curSum = A[i];
            }else{
                curSum +=A[i];
            }
            
            if (sum < curSum){
                sum = curSum;
            }
        }
        return sum;
    }
};
