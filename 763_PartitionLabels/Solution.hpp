class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res, pos(26, 0);
        for (int i = 0; i < S.size(); i++){
            pos[S[i] - 'a'] = i;
        }
        for (int i = 0, lastId = 0, idx = INT_MIN; i < S.size(); i++){
            idx = max(idx, pos[S[i] - 'a']);
            if (idx == i){
                res.push_back(idx - exchange(lastId, i+1) + 1);
            }
        }
        return res;
    }
};
