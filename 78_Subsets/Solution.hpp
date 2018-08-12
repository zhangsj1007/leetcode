class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> dummy;
        ret.push_back(dummy);
        
        for (int i = 0; i < nums.size(); i++){
            int currSize = ret.size();
            for(int j = 0; j < currSize; j++){
                vector<int> t = ret[j];
                t.push_back(nums[i]);
                ret.push_back(t);
            }
        }
        
        return ret;
    }
};
