class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string a(s);
        size_t pos = a.rfind(" ");
        int count = 0;
        int i, j;
        if (pos == string::npos){
            if (a.length() == 0){
                return 0;
            }else{
                return a.length();
            }
        }
        
        if (pos == a.length() - 1){
            for (i = pos; i >= 0; i--){
                if(a[i] != ' '){
                    break;
                }
            }
            for (j = i; j >= 0; j--){
                if (a[j] == ' '){
                    break;
                }
                count++;
            }
            return count;
        }
        
        return a.length() - pos - 1;
    }
};
