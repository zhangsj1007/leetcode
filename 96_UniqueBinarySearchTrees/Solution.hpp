class Solution {
public:
    //dp algorithm
    int numTrees(int n) {
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= n; i++){
            int t = 0;
            for (int j = 0; j < i ; j++)
                t += v[j] * v[i-j-1];
            v.push_back(t);
        }
        return v[n];
    }
};
