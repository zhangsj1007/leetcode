class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> mp;
        vector<int> ret;
        for (auto n : nums){
            while(!stk.empty() && n > stk.top()){
                mp.insert(make_pair(stk.top(), n));
                stk.pop();
            }
            stk.push(n);
        }
        
        for (auto n : findNums){
            if (mp.find(n) != mp.end()){
                ret.push_back(mp[n]);
            }else{
                ret.push_back(-1);
            }
        }
        return ret;
    }
};
