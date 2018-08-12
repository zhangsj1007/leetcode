class Solution {
public:
    int countBinarySubstrings(string s) {
        int preCnt = 0;
        int curCnt = 1;
        int res = 0;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1]){
                curCnt++;
            }else{
                preCnt = curCnt;
                curCnt = 1;
            }
            if (preCnt >= curCnt){
                res++;
            }
        }
        return res;
    }
};
