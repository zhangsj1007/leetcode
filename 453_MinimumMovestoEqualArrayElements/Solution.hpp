//desc:数学算法

class Solution {
public:
    int minMoves(vector<int>& nums) {
        vector<int>::iterator iter = min_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - nums.size() * (*iter);
    }
};
