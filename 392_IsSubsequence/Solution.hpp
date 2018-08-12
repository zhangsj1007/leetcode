class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;
        int i = 0;
        std::size_t found = t.find(s[i++]);
        for (; i < s.length(); i++){
            found = t.find(s[i], found+1);
            if (found == std::string::npos){
                return false;
            }
        }
        return true;
    }
};
