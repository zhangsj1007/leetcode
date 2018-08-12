class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t;
        while(nums[nums[0]] != nums[0]){
                t = nums[nums[0]];
                nums[nums[0]] = nums[0];
                nums[0] = t;
        }
        return nums[0];
    }
};
