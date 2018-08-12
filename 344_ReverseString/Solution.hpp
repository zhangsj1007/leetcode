class Solution {
public:
    string reverseString(string s) {
        int size = s.size();
        string t(size, 0);
        for (int i = 0; i < size; i++){
            t[i] = s[size-1-i];
        }
        return t;
    }
};
