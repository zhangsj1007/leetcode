class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string prefix = "";
        for (int index = 0; index < strs[0].size(); index++, prefix = strs[0].substr(0, index)){
            for (int i = 1; i < strs.size(); i++){
                if (index >= strs[i].size() || (i > 0 && strs[i][index] != strs[i-1][index]))
                    return prefix;
            }
        }
        return prefix;
    }
};
