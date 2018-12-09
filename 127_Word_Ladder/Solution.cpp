/**
date : 2018-09-01
description : bfs get shortest path
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() == 0 || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        queue<string> q;
        map<string, int> strReachRank;
        q.push(beginWord);
        strReachRank[beginWord] = 1;
        while (!q.empty()){
            string str = q.front();
            q.pop();
            vector<string>::iterator iter = wordList.begin();
            while(iter != wordList.end()){
                string &neighStr = *iter;
                if (isNeighbor(str, neighStr)){
                    strReachRank[neighStr] = strReachRank[str] + 1;
                    if (neighStr == endWord)
                        return strReachRank[neighStr];
                    q.push(neighStr);
                    iter = wordList.erase(iter);
                }else
                    iter++;
            }
        }
        return 0;
    }
private:
    bool isNeighbor(string &s1, string &s2){
        int diffCnt = 0;
        int num = s1.size();
        for (int i = 0; i < num; i++){
            if (s1[i] != s2[i])
                diffCnt++;
            if (diffCnt > 1)
                return false;
        }
        return diffCnt == 1;
    }
};
