class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> numSet;
        set<int> numSet2;
        for (int i = 0; i < nums1.size(); i++)
            numSet.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++){
            if (numSet.count(nums2[i]))
                numSet2.insert(nums2[i]);
        }
        vector<int> ans(numSet2.begin(), numSet2.end());
        return ans;
    }
};
