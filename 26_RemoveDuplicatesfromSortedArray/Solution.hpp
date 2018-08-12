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
        p = 0;
        flag = 0;
        
        while(b < n){
            while(b < n && A[a] == A[b]){
                flag = 1;
                b++;
            }
            
            if (b < n){
                if (flag == 1){
                    A[++p] = A[b];
                    a = b;
                    b++;
                    flag = 0;
                }else{
                    A[++p] = A[b];
                    a++;
                    b++;
                }
            }
        }
        
        return p + 1;
    }
};
