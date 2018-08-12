class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int> > s;
        vector<int> holder;
        findSubsequencesHelper(s, holder, 0 ,nums);
        vector<vector<int> > ret(s.begin(), s.end());
        return ret;
    }
    
    void findSubsequencesHelper(set<vector<int> >&s, vector<int> holder, int index, vector<int>& nums){
        if (holder.size() >= 2){
            s.insert(holder);
        }
        
        for(int i = index; i < nums.size(); i++){
            if (holder.size() == 0 || holder[holder.size()-1] <= nums[i]){
                holder.push_back(nums[i]);
                findSubsequencesHelper(s, holder, i+1, nums);
                holder.pop_back();
            }
        }
    }
};
