class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0;  
        unordered_map<int, int> hash;  
          
        hash[0] = 1;  
        for(auto n:nums) {  
            sum += n;  
            cnt += hash[sum-k];  
            ++hash[sum];  
        }  
          
        return cnt;  
    }
};
