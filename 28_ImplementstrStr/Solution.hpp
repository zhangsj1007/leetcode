class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (strlen(needle) == 0 || needle == NULL){
            return 0;
        }
        
        int i, j, k;
        
        for (i = 0; i < strlen(haystack); i++){
            if (strlen(haystack) - i < strlen(needle)){ //如果小于这个needle的长度，不用考虑，有效节省时间。
                return -1;
            }
            k = 0;
            for (j = i; j < strlen(haystack); j++){
                if (needle[k] == haystack[j]){
                    if (k == strlen(needle) - 1){
                        return i;
                    }
                    k++;
                }else{
                    break;
                }
            }
        }
        
        return -1;
    }
};
