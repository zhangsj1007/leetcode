class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        if (nums.size() == 0)
            return v;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            if (m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else
                m[nums[i]] += 1;
        }
        vector<pair<int, int> > pairV(m.begin(), m.end());
        sort(pairV.begin(), pairV.end(), CmpByValue());
        for(int i = 0; i < k; i++){
            v.push_back(pairV[i].first);
            
        }
        return v;
    }
    
    //bool cmpByValue(pair<int, int> &p1, pair<int, int> &p2){
    //    return p1.second > p2.second;
    //}
    struct CmpByValue{
        bool operator()(pair<int, int> &p1, pair<int, int> &p2){
            return p1.second > p2.second;
        }
    };
};
