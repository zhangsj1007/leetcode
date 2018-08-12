class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (str.length() == 1 ) return false;
        int i = 1;
        int j = 0;
        bool flag = false; 
        vector<int> next(str.length()+1, 0);
        while(i < str.length()){
            while(j > 0 && str[i] != str[j]) j = next[j];
            if (str[i] == str[j]) j++;
            next[i+1] = j;
            i++;
        }
        int subStrLen = str.length() - next[str.length()];
        if (subStrLen == str.length() || subStrLen > str.length() / 2) return false;
        for (i = subStrLen; i < str.length(); ){
            for (int k = 0; k < subStrLen; k++, i++){
                if (i >= str.length() || str[k] != str[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
