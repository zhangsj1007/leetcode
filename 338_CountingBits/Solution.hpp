class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        v[0] = 0;
        if (num > 0)
            v[1] = 1;
        for (int i = 2; i <= num; i++){
            v[i] = v[i>>1] + (i & 1);
        }
        return v;
    }
};
