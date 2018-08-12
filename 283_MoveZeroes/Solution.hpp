class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index1;
        int index2;
        int t;
        index1 = 0;
        index2 = 0;
        while(nums[index1] != 0)
            index1++;
        index2 = index1;
        
        do{
            while(nums[index1] == 0 && index1 < nums.size())
                index1++;
            while(nums[index2] != 0 && index1 > index2)
                index2++;
            if(index1 == nums.size())
                continue;
            t = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = t;
        }while(index1 > index2 && index1 < nums.size() - 1);
    }
};
