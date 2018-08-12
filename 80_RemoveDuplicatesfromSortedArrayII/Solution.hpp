class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        
        int a;
        int b;
        int p;
        int flag;
        
        a = 0;
        b = 1;
        p = -1;
        flag = 0;
        
        while(b < n){
            while(b < n && A[a] == A[b]){
                flag = 1;
                b++;
            }
            
            if (flag == 1){
                    A[++p] = A[a];
                    A[++p] = A[a];
                    a = b;
                    b++;
                    flag = 0;
            }else{
                    A[++p] = A[a];
                    a++;
                    b++;
            }
        }
        if (A[n-1] != A[n-2]){
            A[++p] = A[a];
        }
            
        return p + 1;
    }
};
