class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int, int> m;
        m.insert(make_pair(0,1));
        for (int i = 1; i <= target; i++){
            int t = 0;
            for (int j = 0; j < nums.size(); j++){
                if (m.count(i-nums[j])){
                    t += m[i-nums[j]];
                }
            }
            m[i] = t;
        }
        return m[target];
    }
};
