class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret;
        set<vector<int> > subs;
        vector<int> dummy;
        ret.push_back(dummy);
        subs.insert(dummy);
        
        for (int i = 0; i < nums.size(); i++){
            int currSize = ret.size();
            for(int j = 0; j < currSize; j++){
                vector<int> t = ret[j];
                t.push_back(nums[i]);
                //对于set来说，[1,2]和[2,1]是不同的元素。
                sort(t.begin(), t.end());
                ret.push_back(t);
                subs.insert(t);
            }
        }
        
        ret.clear();
        ret.assign(subs.begin(), subs.end());
        
        return ret;
    }
};
