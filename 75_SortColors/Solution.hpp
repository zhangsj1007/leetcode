class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int white = 0;
        int blue = 0;
        int i;
        
        for (i = 0; i < n; i++){
            if (A[i] == 0){
                red++;
            }else if (A[i] == 1){
                white++;
            }else{
                blue++;
            }
        }
        
        for (i = 0; i < red; i++){
            A[i] = 0;
        }
        
        for (i = red; i < red + white; i++){
            A[i] = 1;
        }
        
        for (i = red + white; i < n; i++){
            A[i] = 2;
        }
    }
};
