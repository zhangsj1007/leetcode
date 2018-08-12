class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for(int i = 0; i < n && maxReach >= i; i++){
            maxReach = max(maxReach, nums[i] + i);
        }
        
        return maxReach >= n - 1;
    }
};
