class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m == 0){
            for(int i = 0; i < n; i++)
                A[i] = B[i];
            return;
        }
        
        int indexA = m - 1;
        int indexB = n - 1;
        int indexNew = m + n - 1;
        
        while (indexA >= 0 && indexB >= 0){
            while(A[indexA] < B[indexB] && indexB >= 0){
                A[indexNew] = B[indexB];
                indexNew--;
                indexB--;
            }
            
            if (indexB < 0)
                break;
                
            while(A[indexA] >= B[indexB] && indexA >= 0){
                A[indexNew] = A[indexA];
                indexNew--;
                indexA--;
            }
        }
            if (indexA >= 0){
                while(indexA >= 0){
                    A[indexNew] = A[indexA];
                    indexNew--;
                    indexA--;
                }
            }
            if (indexB >= 0){
                while(indexB >= 0){
                    A[indexNew] = B[indexB];
                    indexNew--;
                    indexB--;
                }
            }
        
    }
};
