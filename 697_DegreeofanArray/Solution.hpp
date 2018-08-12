class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, vector<int>> numIndexMp;
        for (int i = 0; i < nums.size(); i++){
            numIndexMp[nums[i]].push_back(i);
        }
        int degree = 1;
        int minDistance = INT_MAX;
        for (auto iter = numIndexMp.begin(); iter != numIndexMp.end(); iter++){
            degree = max(degree, (int)iter->second.size());
        }
        for (auto iter = numIndexMp.begin(); iter != numIndexMp.end(); iter++){
            if (iter->second.size() == degree){
                minDistance = min(minDistance, (iter->second.back() - iter->second.front() + 1));
            }
        }
        return minDistance;
    }
};
