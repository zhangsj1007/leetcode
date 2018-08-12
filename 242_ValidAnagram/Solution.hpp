class Solution {
public:
    bool isAnagram(string s, string t) {
        int *p1 = 0;
        int *p2 = 0;
        p1 = charTable(s);
        p2 = charTable(t);
        for(int i = 0; i < 26; i++)
            if (p1[i] != p2[i])
                return false;
        return true;
    }
    int* charTable(string s){
        int *p = new int[26];
        for (int i = 0; i < 26; i++)
            p[i] = 0;
            
        for (int i = 0; i < s.size(); i++)
            p[static_cast<int>(s[i] - 'a')]++;
        return p;
    }
};
