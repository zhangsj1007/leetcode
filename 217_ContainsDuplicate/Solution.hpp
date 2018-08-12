class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //sort is used to array and vector
        sort(nums.begin(), nums.end());
        //unique should be sorted firstly, then return the last element that is unique. 
        return unique(nums.begin(), nums.end()) != nums.end();
    }
};
