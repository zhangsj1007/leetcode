class Solution {
public:
    string reverseVowels(string s) {
        string vowelStr;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                vowelStr.append(1, s[i]);
        }
        if (vowelStr.length() == 0 || vowelStr.length() == 1){
            return s;
        }
        for (int i = 0; i <= (vowelStr.length() - 1)/ 2; i++){
            char t = vowelStr[i];
            vowelStr[i] = vowelStr[vowelStr.length() - 1 - i];
            vowelStr[vowelStr.length() - 1 - i] = t;
        }
        for (int i = 0, j = 0; i < s.length(); i++){
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s[i] = vowelStr[j];
                j++;
            }
        }
        return s;
    }
};
