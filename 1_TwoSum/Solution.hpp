class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pairs;
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i++){
            if (pairs.count(nums[i]) == 0){
                pairs[target - nums[i]] = i;
            }else{
                ret.push_back(pairs[nums[i]]);
                ret.push_back(i);
                return ret;
            }
        }
        
        return ret;
    }
};
