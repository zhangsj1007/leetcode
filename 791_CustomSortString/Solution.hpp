class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&](int a, int b){return S.find(a) < S.find(b);});
        return T;
    }
};
