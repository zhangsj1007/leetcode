class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        bitset<32> xbit(x);
        bitset<32> ybit(y);
        for (int i = 0; i < 31; i++){
            if (xbit[i] != ybit[i]){
                count++;
            }
        }
        return count;
    }
};
