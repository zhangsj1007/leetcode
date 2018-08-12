class Solution {
public:
    void reverseWords(string &s) {
         for(int i = s.length() - 1; i >= 0; i-- ){
            if (s[i] == ' '){
                s.erase(i, 1);
            }else{
                break;
            }
        } 
        ReverseString(s, 0, s.length() - 1);
        for(int i = s.length() - 1; i >= 0; i-- ){
            if (s[i] == ' '){
                s.erase(i, 1);
            }else{
                break;
            }
        }

        int begin = 0;
        int end = 0;
        while(s[begin] != '\0'){
            if(s[end] == ' '){
                for (int i = end + 1; s[i] == ' ';){//清除连续的空格
                    s.erase(i, 1);
                }
                /*if (s[end + 1] == ' '){
                    s.erase(end + 1, 1);
                }*/
                ReverseString(s, begin, end-1);
                end++;
                begin = end;
            }else if(s[end] == '\0'){
                ReverseString(s, begin, end-1);
                begin = end;
            }else{
                end++;
            }
        }
    }
    void ReverseString(string &s, int begin, int end){
        char temp;
        for (; begin < end; begin++, end--){
            temp = s[begin];
            s[begin] = s[end];
            s[end] = temp;
        }
    }
};
