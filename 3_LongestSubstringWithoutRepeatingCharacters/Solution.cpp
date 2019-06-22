class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /*if (s.size() == 0)
            return 0;
        
        int record[128];
        memset(record, -1, sizeof(record));
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); i++){
            char c = s[i];
            int ii = (int)c;
            int iii = record[ii];
            if (iii == -1){
                record[ii] = i;
            }else{
                int length = 0;
                for (int j = 0; j < 128; j++){
                    if (record[j] != -1){
                        length++;
                        if (record[j] <= iii)
                            record[j] = -1;       
                    }
                }
                record[ii] = i;
                maxLength = max(maxLength, length);
            }
        }
        
        
        int length = 0;
        for (int i = 0; i < 128; i++){
            if (record[i] != -1)
                length++;
        }
        
        maxLength = max(maxLength, length);
        
        return maxLength;*/


        int dict[128];
        memset(dict, -1, sizeof(dict));
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
