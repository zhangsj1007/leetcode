class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m1;
        map<int, int> m2;
        vector<int> ans;
        for (auto val : nums1)
            m1[val] += 1;
        for (auto val : nums2)
            m2[val] += 1;
        for(auto p : m1){
            if (m2.count(p.first)){
                vector<int> tvector(min(p.second, m2[p.first]), p.first);
                ans.insert(ans.end(), tvector.begin(), tvector.end());
            }
        }
        
        return ans;
    }
};
