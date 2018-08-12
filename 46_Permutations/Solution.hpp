class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        vector<vector<int> > v;
        permutateImpl(start, end, nums, v);
        return v;
    }
    
    void permutateImpl(int start, int end, vector<int>& nums, vector<vector<int> >& v){
        if (start == end){
            v.push_back(nums);
            return;
        }
        
        for (int i = start; i <= end; i++){
            swap(nums[start], nums[i]);
            permutateImpl(start+1, end, nums, v);
            swap(nums[start], nums[i]);
        }
    }
    
};
