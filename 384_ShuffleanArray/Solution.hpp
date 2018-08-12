class Solution {
public:
    Solution(vector<int> nums) : nums_(nums){
    
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(nums_);
        for (int i = 0; i < nums_.size(); i++){
            int pos = rand() % (nums_.size() - i);
            swap(ret[i], ret[i+pos]);
        }
        return ret;
    }
private:
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
