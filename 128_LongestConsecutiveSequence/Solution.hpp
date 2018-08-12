class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int val , len = 0, c = 0, val1;
       // unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> set(nums.begin(), nums.end());
        while(!set.empty()){
            val = *set.begin(),
            set.erase(val);
            len = 1;
            val1 = val;
            while(set.find(++val1) != set.end()){
                len++;
                set.erase(val1);
            }
            val1 = val;
            while(set.find(--val1) != set.end()){
                len++;
                set.erase(val1);
            }
            c = max(c, len);
        }
        return c;
    }
    /*int longestConsecutive(vector<int>& nums) {
        int len = 0, candidate, val;
        unordered_set<int> set(nums.begin(), nums.end());
        while (!set.empty()) {
            val = *set.begin();
            set.erase(val);
            candidate = 1;
            for (int i = val + 1; set.find(i) != set.end(); ++i) {
                set.erase(i);
                candidate++;
            }
            for (int i = val - 1; set.find(i) != set.end(); --i) {
                set.erase(i);
                candidate++;
            }
            len = max(len, candidate);
        }
        return len;
    }*/
    
};
