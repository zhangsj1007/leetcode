class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int t1;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == -1)
                continue;
            if (nums[i] == nums.size()){
                nums[i] = -1;
                continue;
            }
            t1 = nums[i];
            nums[i] = nums[nums[i]];
            nums[nums[i]] = t1;
            if (nums[i] == nums.size()){
                nums[i] = -1;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == -1)
                return i;
        return nums.size();*/
        int big = 0;
        int small = 0;
        for (int i = 0; i < nums.size(); i++){
            big += i + 1;
            small += nums[i];
        }
        return big - small;
    }
};
