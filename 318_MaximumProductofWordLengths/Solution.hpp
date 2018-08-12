/*
    算法：解法中最精髓的是采用了按位做运算来判定两个string是否有公共的元素，之前自己的做法是用find_first_of这样也能实现，但是效率极低，导致时间不合格。这是比较两个集合，对于不仅仅是26个字母的情况下的大的文本可以采用md5，其实是一样的道理，都是一种  类似于hash的方法。
*/


class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks(words.size());
        int i, j, k;
        int result = 0;
        for (i = 0; i < words.size(); i++){
            int mask = 0;
            for(j = 0; j < words[i].size(); j++){
                mask |= 1 << (words[i][j] - 'a') ; 
            }
            masks[i] = mask;
            for (k = 0; k < i; k++)
                if (!(masks[i] & masks[k]))
                    result = max(result, static_cast<int>(words[i].size() * words[k].size()));
        }
        return result;
    }
};
