class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int small = 1;
        int big = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] < nums[i])
                big = small + 1;
            else if (nums[i-1] > nums[i])
                small = big + 1;
        }
        return max(small, big);
    }
};
