class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int pos = -1;
        if (ransomNote.size() == 0)
            return true;
        if (magazine.size() == 0)
            return false;
        for (int i = 0; i < ransomNote.size(); i++){
            //if (pos + 1 == magazine.size()) return false;
            if ((pos = magazine.find(ransomNote[i], 0)) == string::npos)
                return false;
            magazine.erase(pos, 1);
            //if (pos >= magazine.size() - 1)
            //    return false;
        }
        return true;
    }
};
